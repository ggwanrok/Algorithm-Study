#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, max_value = 0;

// 보드를 밀어내는 함수
void move(vector<vector<int>>& board, int direction, int r, int c) {
    if (direction == 0) { // 위쪽
        for (int i = 0; i < n; i++) {
            if (board[i][c] == 0) {
                for (int j = i + 1; j < n; j++) {
                    if (board[j][c] != 0) {
                        swap(board[i][c], board[j][c]);
                        break;
                    }
                }
            }
        }
    } else if (direction == 1) { // 오른쪽
        for (int i = n - 1; i >= 0; i--) {
            if (board[r][i] == 0) {
                for (int j = i - 1; j >= 0; j--) {
                    if (board[r][j] != 0) {
                        swap(board[r][i], board[r][j]);
                        break;
                    }
                }
            }
        }
    } else if (direction == 2) { // 아래쪽
        for (int i = n - 1; i >= 0; i--) {
            if (board[i][c] == 0) {
                for (int j = i - 1; j >= 0; j--) {
                    if (board[j][c] != 0) {
                        swap(board[i][c], board[j][c]);
                        break;
                    }
                }
            }
        }
    } else { // 왼쪽
        for (int i = 0; i < n; i++) {
            if (board[r][i] == 0) {
                for (int j = i + 1; j < n; j++) {
                    if (board[r][j] != 0) {
                        swap(board[r][i], board[r][j]);
                        break;
                    }
                }
            }
        }
    }
}

// 보드를 합치는 함수
void merge(vector<vector<int>>& board, int direction, int r, int c) {
    if (direction == 0) { // 위쪽
        for (int i = 0; i < n - 1; i++) {
            if (board[i][c] != 0 && board[i][c] == board[i + 1][c]) {
                board[i][c] *= 2;
                board[i + 1][c] = 0;
            }
        }
        move(board, direction, r, c);
    } else if (direction == 1) { // 오른쪽
        for (int i = n - 1; i > 0; i--) {
            if (board[r][i] != 0 && board[r][i] == board[r][i - 1]) {
                board[r][i] *= 2;
                board[r][i - 1] = 0;
            }
        }
        move(board, direction, r, c);
    } else if (direction == 2) { // 아래쪽
        for (int i = n - 1; i > 0; i--) {
            if (board[i][c] != 0 && board[i][c] == board[i - 1][c]) {
                board[i][c] *= 2;
                board[i - 1][c] = 0;
            }
        }
        move(board, direction, r, c);
    } else { // 왼쪽
        for (int i = 0; i < n - 1; i++) {
            if (board[r][i] != 0 && board[r][i] == board[r][i + 1]) {
                board[r][i] *= 2;
                board[r][i + 1] = 0;
            }
        }
        move(board, direction, r, c);
    }
}

// 게임 백트래킹 함수
void game(vector<vector<int>> board, int moves) {
    if (moves == 5) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                max_value = max(max_value, board[i][j]);
            }
        }
        return;
    }

    for (int direction = 0; direction < 4; direction++) {
        vector<vector<int>> temp = board; // 보드 상태 복사
        if (direction == 0) { // 위쪽
            for (int col = 0; col < n; col++) {
                move(temp, direction, 0, col);
                merge(temp, direction, 0, col);
            }
        } else if (direction == 1) { // 오른쪽
            for (int row = 0; row < n; row++) {
                move(temp, direction, row, 0);
                merge(temp, direction, row, 0);
            }
        } else if (direction == 2) { // 아래쪽
            for (int col = 0; col < n; col++) {
                move(temp, direction, 0, col);
                merge(temp, direction, 0, col);
            }
        } else { // 왼쪽
            for (int row = 0; row < n; row++) {
                move(temp, direction, row, 0);
                merge(temp, direction, row, 0);
            }
        }
        game(temp, moves + 1);
    }
}


int main() {
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    game(board, 0);
    cout << max_value << endl;
    return 0;
}
