#include <bits/stdc++.h>

using namespace std;

// 방향: 우 - 하 - 좌 - 상
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int direct;
int n, k, l;
int arr[104][104]; // 사과 위치
int checked[104][104]; // 뱀 몸 위치 체크
queue<int> time_queue;
queue<char> way_queue;
deque<pair<int, int>> snake; // 뱀 몸 전체 추적

bool check_possible_moving(int x, int y) {
    if (x >= 1 && x <= n && y >= 1 && y <= n && checked[x][y] == 0) return true;
    return false;
}

int main() {
    direct = 0;
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        arr[r][c] = 1; // 사과 위치 저장
    }

    cin >> l;
    for (int i = 0; i < l; i++) {
        int time;
        char way;
        cin >> time >> way;
        time_queue.push(time);
        way_queue.push(way);
    }

    int total_time = 0;
    snake.push_back({1, 1});
    checked[1][1] = 1;

    while (true) {
        total_time++;
        int nx = snake.front().first + dx[direct];
        int ny = snake.front().second + dy[direct];

        if (!check_possible_moving(nx, ny)) break;

        snake.push_front({nx, ny});
        checked[nx][ny] = 1;

        if (arr[nx][ny] == 1) {
            arr[nx][ny] = 0;
        } else {
            checked[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }

        if (!time_queue.empty() && total_time == time_queue.front()) {
            if (way_queue.front() == 'D') {
                direct = (direct + 1) % 4;
            } else {
                direct = (direct - 1 + 4) % 4;
            }
            time_queue.pop();
            way_queue.pop();
        }
    }

    cout << total_time << '\n';
    return 0;
}