import sys
input = sys.stdin.readline

N = int(input())
res = 0

col = [False] * N       # 같은 열에 퀸이 있는지 확인
diag1 = [False] * (2*N) # '/' 방향 대각선 검사 (row + col)
diag2 = [False] * (2*N) # '\' 방향 대각선 검사 (row - col + N)

def n_queens(row):
    global res
    if row == N:
        res += 1
        return
    
    for c in range(N):
        if not col[c] and not diag1[row + c] and not diag2[row - c + N]:
            # 퀸 배치
            col[c] = diag1[row + c] = diag2[row - c + N] = True
            n_queens(row + 1)
            # 원래대로 되돌리기 (백트래킹)
            col[c] = diag1[row + c] = diag2[row - c + N] = False

n_queens(0)
print(res)
