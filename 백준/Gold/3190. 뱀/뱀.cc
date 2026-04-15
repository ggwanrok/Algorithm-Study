#include <bits/stdc++.h>
using namespace std;

// 우, 하, 좌, 상
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n, k, l;
int board[104][104];
map<int, char> direction_change;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    // 사과 위치
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1; // 사과
    }

    cin >> l;
    for (int i = 0; i < l; i++) {
        int t;
        char d;
        cin >> t >> d;
        direction_change[t] = d;
    }

    deque<pair<int, int>> snake;
    snake.push_back({1, 1});
    int dir = 0;
    int time = 0;
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
    visited[1][1] = true;

    while (true) {
        time++;
        int nx = snake.front().first + dx[dir];
        int ny = snake.front().second + dy[dir];

        // 벽이나 자기 자신과 충돌하면 종료
        if (nx < 1 || ny < 1 || nx > n || ny > n || visited[nx][ny]) {
            break;
        }

        // 이동
        snake.push_front({nx, ny});
        visited[nx][ny] = true;

        if (board[nx][ny] == 1) {
            // 사과가 있으면 꼬리 안 움직임
            board[nx][ny] = 0;
        } else {
            // 사과 없으면 꼬리 제거
            auto tail = snake.back();
            visited[tail.first][tail.second] = false;
            snake.pop_back();
        }

        // 방향 전환
        if (direction_change.count(time)) {
            if (direction_change[time] == 'D') {
                dir = (dir + 1) % 4;
            } else {
                dir = (dir + 3) % 4;
            }
        }
    }

    cout << time << '\n';
    return 0;
}