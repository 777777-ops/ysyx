echo "Running unit tests:"

for i in tests/*_tests
do
    if test -f $i
    then
	echo "***************************************"
        args_file="${i%_tests}_args.txt"
       	#echo "args_file 的文件名字是: $args_file" 
        if test -f "$args_file"
        then
            # 存在参数文件，按行读取每组参数
            echo "Running $i with parameters from $args_file"
            line_number=0
            
            while IFS= read -r line || [ -n "$line" ]
            do
                line_number=$((line_number + 1))
               
                # 跳过空行和注释行（以#开头的行）
                if [ -z "$line" ] || echo "$line" | grep -q '^[[:space:]]*#'; then
                    continue
                fi

                # 去除行首行尾的空白字符
                line=$(echo "$line" | sed -e 's/^[[:space:]]*//' -e 's/[[:space:]]*$//')
                
                if [ -n "$line" ]; then
		    echo "---------------------"                    
                    echo "Test $line_number: ./$i $line"
                    #if $VALGRIND ./$i $line 2>> tests/tests.log
                    if eval "./$i $line" 2>> tests/tests.log
                    then
                        echo "  $i with args '$line' PASS"
                    else
                        echo "ERROR in test $i (line $line_number): ./$i $line"
                        tail tests/tests.log
                        exit 1
                    fi
		    echo "---------------------"
                fi
            done < "$args_file"
        else
	    echo "-------stdout--------"
	    if ./$i 2>> tests/tests.log
	    echo "-------stdout--------"
            then
            	echo $i PASS
            else
            	echo "ERROR in test $i: here's tests/tests.log"
            	echo "------"
            	tail tests/tests.log
            	exit 1
	    fi
        fi
	echo "***************************************"
    fi
done

echo ""

