import sys
sys.setrecursionlimit(10000)

arr = [-1] * 10001
arr[0] = 0
arr[1] = 1
arr[2] = 1

def fibo(i):
    if arr[i] != -1:
        return arr[i]
    arr[i] = fibo(i - 1) + fibo(i - 2)
    return arr[i]

n = int(input())
print(fibo(n))