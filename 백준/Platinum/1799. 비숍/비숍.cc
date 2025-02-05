#include <bits/stdc++.h>

using namespace std;

int n;
int res_black, res_white;
vector<vector<int>> board;
vector<vector<int>> b_shop;

bool verify(int r, int c) {
    for (int i = 1; r - i >= 0 && c - i >= 0; i++) {
        if (b_shop[r - i][c - i]) return false;
    }
    for (int i = 1; r - i >= 0 && c + i < n; i++) {
        if (b_shop[r - i][c + i]) return false;
    }
    return true;
}

void input() {
    cin >> n;
    board.resize(n, vector<int>(n));
    b_shop.resize(n, vector<int>(n, 0));
    res_black = 0;
    res_white = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
}

void chess(int color, int num, int cnt) {
    if (num >= n * n) {
        if (color == 0) res_black = max(res_black, cnt);
        else res_white = max(res_white, cnt);
        return;
    }

    int r = num / n;
    int c = num % n;

    if ((r + c) % 2 == color) {  // 색깔에 맞는 칸만 탐색
        if (board[r][c]) {  // 비숍을 놓을 수 있는 경우
            if (verify(r, c)) {
                b_shop[r][c] = 1;
                chess(color, num + 1, cnt + 1);
                b_shop[r][c] = 0;
            }
        }
    }
    chess(color, num + 1, cnt);
}

void output() {
    cout << res_black + res_white << '\n';
}

void func() {
    chess(0, 0, 0);  // 검은색 칸
    chess(1, 0, 0);  // 흰색 칸
}

int main() {
    input();
    func();
    output();
    return 0;
}
