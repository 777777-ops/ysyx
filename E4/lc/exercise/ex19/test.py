#!/usr/bin/env python3
import subprocess
import time

def run_game_test():
    """游戏自动化测试 - 简化版"""
    proc = subprocess.Popen(['stdbuf', '-o0', './ex19'], 
                          stdin=subprocess.PIPE,
                          stdout=subprocess.PIPE,
                          text=True,
                          bufsize=1)
    
    # 读取直到第一个提示符
    output = ""
    while '> ' not in output:
        output += proc.stdout.read(1)
    print("游戏启动成功")
    
    commands = ['l', 'n', 'a', 'w', 'a']
    
    for cmd in commands:
        proc.stdin.write(cmd + '\n')
        proc.stdin.flush()
        
        # 读取直到下一个提示符
        output = ""
        while '> ' not in output:
            output += proc.stdout.read(1)
        
        print(f"执行命令 '{cmd}' 的输出:")
        print(output[:-4])
        print("-" * 40)
    
    proc.terminate()

if __name__ == "__main__":
    run_game_test()
