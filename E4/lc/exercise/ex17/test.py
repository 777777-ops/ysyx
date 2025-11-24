import subprocess
import sys
import os

def run_command(cmd):
    """运行命令并打印输出 - 兼容Python 3.6"""
    print(f"执行: {cmd}")
    # 使用完全兼容Python 3.6的写法
    result = subprocess.run(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    
    # 手动解码输出
    stdout = result.stdout.decode('utf-8').strip() if result.stdout else ""
    stderr = result.stderr.decode('utf-8').strip() if result.stderr else ""
    
    if stdout:
        print(f"输出: {stdout}")
    if stderr:
        print(f"错误: {stderr}")
    
    return result.returncode == 0

def main():
    db_file = "db.dat"
    
    print("🧪 开始测试ex17数据库程序...")
    
    # 清理之前的测试文件
    if os.path.exists(db_file):
        os.remove(db_file)
    
    # 1. 创建数据库
    print("\n1. 创建数据库...")
    run_command(f"./ex17 {db_file} c 10 3")
    
    # 2. 添加测试数据
    print("\n2. 添加测试数据...")
    run_command(f"./ex17 {db_file} s 1 zed zed@zedshaw.com")
    run_command(f"./ex17 {db_file} s 2 frank frank@zedshaw.com")
    run_command(f"./ex17 {db_file} s 3 joe joe@zedshaw.com")
    
    # 3. 列出所有数据
    print("\n3. 列出所有数据...")
    run_command(f"./ex17 {db_file} l")
    
    # 4. 删除一条数据
    print("\n4. 删除ID为3的数据...")
    run_command(f"./ex17 {db_file} d 3")
    
    # 5. 再次列出数据
    print("\n5. 删除后列出数据...")
    run_command(f"./ex17 {db_file} l")
    
    # 6. 获取特定数据
    print("\n6. 获取ID为2的数据...")
    run_command(f"./ex17 {db_file} g 2")
    
    print("\n✅ 测试流程完成！")

if __name__ == "__main__":
    main()
