#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define null 0

struct Address {
    int id;
    int set;
    char *name;
    char *email;
};

struct Database {
    int max_rows;
    int data_length;
    struct Address *rows;
};

struct Connection {
    FILE *file;
    struct Database *db;
};

void Database_close(struct Connection *conn);

void die(const char *message, struct Connection *conn)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
    
    Database_close(conn);
    exit(1);
}

void Address_print(struct Address *addr)
{
    printf("%d %s %s\n",
            addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn){

    
    if(!fread(&conn->db->max_rows, sizeof(int), 1, conn->file))   goto die;
    if(!fread(&conn->db->data_length, sizeof(int), 1, conn->file))  goto die;
    conn->db->rows = (struct Address*)malloc(conn->db->max_rows * sizeof(struct Address)); 
    if(conn->db->rows == null) goto die;
 
    struct Address* rs = conn->db->rows;
    for(int i = 0; i < conn->db->max_rows; i++){
        if(!fread(&rs[i].id, sizeof(int), 1, conn->file))  goto die;
        if(!fread(&rs[i].set, sizeof(int), 1, conn->file))  goto die;

        rs[i].name = (char *)malloc(conn->db->data_length * sizeof(char));
        if(rs[i].name == null) goto die;
        if(!fread(rs[i].name, conn->db->data_length * sizeof(char), 1, conn->file))  goto die;

        rs[i].email = (char *)malloc(conn->db->data_length * sizeof(char));
        if(rs[i].email == null) goto die;
        if(!fread(rs[i].email, conn->db->data_length * sizeof(char), 1, conn->file))  goto die;
    
     }
    
    return;

die:
    die("Failed to load database.", conn);
}

struct Connection *Database_open(const char *filename, char mode)
{
    struct Connection *conn = malloc(sizeof(struct Connection));
    if(!conn) die("Memory error", conn);

    conn->db = malloc(sizeof(struct Database));
    if(!conn->db) die("Memory error", conn);

    if(mode == 'c') {
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");

        if(conn->file) {
            Database_load(conn);
        }
    }

    if(!conn->file) die("Failed to open the file", conn);

    return conn;
}

void Database_close(struct Connection *conn)
{
    if(conn) {
        if(conn->file) fclose(conn->file);
        if(conn->db){
            struct Address* addr = conn->db->rows;
            for(int i = 0; i < conn->db->max_rows; i++){       
                if(addr[i].name) free(addr[i].name);
                if(addr[i].email) free(addr[i].email);
            }    
            free(conn->db->rows);
        }
        free(conn);
    }
}

void Database_write(struct Connection *conn)
{
    rewind(conn->file);

    if(!fwrite(&conn->db->max_rows, sizeof(int), 1, conn->file))   goto die;
    if(!fwrite(&conn->db->data_length, sizeof(int), 1, conn->file))  goto die;
 
    struct Address* rs = conn->db->rows;
    for(int i = 0; i < conn->db->max_rows; i++){
        if(!fwrite(&rs[i].id, sizeof(int), 1, conn->file))  goto die;
        if(!fwrite(&rs[i].set, sizeof(int), 1, conn->file))  goto die;

        if(!fwrite(rs[i].name, conn->db->data_length * sizeof(char), 1, conn->file))  goto die;
        if(!fwrite(rs[i].email, conn->db->data_length * sizeof(char), 1, conn->file))  goto die;
   }

    if(fflush(conn->file) == -1) goto die;
    return;
die:
    die("error", conn);
}

void Database_create(struct Connection *conn, int max_rows, int data_length){
    int i = 0;

    conn->db->max_rows = max_rows;
    conn->db->data_length = data_length;
    conn->db->rows = (struct Address*)malloc(max_rows * sizeof(struct Address));
    if(conn->db->rows == null) goto die;    
    
    struct Address* rs = conn->db->rows;
    for(i = 0; i < max_rows; i++) {
        rs[i].id = i;
        rs[i].set = 0;
        rs[i].name = (char*)calloc(data_length * sizeof(char), 1);
        if(rs[i].name == null) goto die;
        rs[i].email = (char*)calloc(data_length * sizeof(char), 1);
        if(rs[i].email == null) goto die;
    }
    return;
die:
    die("error", conn);
}


void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
    struct Address *addr = &conn->db->rows[id];
    int data_length = conn->db->data_length;
    if(addr->set) die("Already set, delete it first", conn);

    addr->set = 1;
    // WARNING: bug, read the "How To Break It" and fix this
    char *res = strncpy(addr->name, name, data_length);
    // demonstrate the strncpy bug
    if(!res) die("Name copy failed", conn);
    else addr->name[data_length - 1] = '\0';
    
    res = strncpy(addr->email, email, data_length);
    if(!res) die("Email copy failed", conn);
    else addr->email[data_length - 1] = '\0';
}

void Database_get(struct Connection *conn, int id)
{
    struct Address *addr = &conn->db->rows[id];

    if(addr->set) {
        Address_print(addr);
    } else {
        die("ID is not set", conn);
    }
}

void Database_delete(struct Connection *conn, int id)
{
    char* zeros = (char*)calloc(conn->db->data_length * sizeof(char), 1);
    if(zeros == null) goto die;
    struct Address *addr = &conn->db->rows[id];
    addr->id = 0;
    addr->set = 0;
    
    if(!strncpy(addr->name, zeros, conn->db->data_length))  goto die;   
    if(!strncpy(addr->email, zeros, conn->db->data_length))  goto die;   
    return;
die:
    die("error", conn);
}       

void Database_list(struct Connection *conn)
{
    int i = 0;
    struct Database *db = conn->db;

    for(i = 0; i < conn->db->max_rows; i++) {
        struct Address *cur = &db->rows[i];

        if(cur->set) {
            Address_print(cur);
        }
    }
}

int main(int argc, char *argv[])
{
    if(argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]", 0);

    char *filename = argv[1];
    char action = argv[2][0];
    struct Connection *conn = Database_open(filename, action);
    int id = 0;
    int data_length = 0;
    int max_rows = 0;

    if(argc > 3) id = atoi(argv[3]);
    if(action != 'c' && action != 'l')
        if(id >= conn->db->max_rows) die("There's not that many records.", conn);
   
     switch(action) {
        case 'c':
            if(argc < 5) die("USAGE: ex17 <dbfile> c <data_length> <max_rows>", null);
            data_length = atoi(argv[3]);
            max_rows = atoi(argv[4]);
            Database_create(conn, max_rows, data_length);
            Database_write(conn);
            break;

        case 'g':
            if(argc != 4) die("Need an id to get", conn);

            Database_get(conn, id);
            break;

        case 's':
            if(argc != 6) die("Need id, name, email to set", conn);

            Database_set(conn, id, argv[4], argv[5]);
            Database_write(conn);
            break;

        case 'd':
            if(argc != 4) die("Need id to delete", conn);

            Database_delete(conn, id);
            Database_write(conn);
            break;

        case 'l':
            Database_list(conn);
            break;
        default:
            die("Invalid action, only: c=create, g=get, s=set, d=del, l=list", conn);
    }

    Database_close(conn);

    return 0;
}
