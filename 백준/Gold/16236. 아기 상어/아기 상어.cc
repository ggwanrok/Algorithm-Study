#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

struct shark {
    int x, y, level, satiety;

    bool can_level_up() {
        return level == satiety;
    }
};

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

vector<tuple<int, int, int>> list;
shark baby;
int n;
int area[21][21];
int res = 0;

bool compare(const tuple<int, int, int>& , const tuple<int, int, int>&);
void input();
void func();
void searching();
bool is_area(int, int);
bool can_eat(int, int);
bool can_move(int, int);
bool eating();
void output();

int main() {
    input();
    func();
    output();
    return 0;
}

void searching() {
    list.clear();
    queue<tuple<int, int, int>> q;  // 큐 초기화 (거리, x, y)
    bool visited[21][21] = {false}; // 방문 체크 배열
    q.push(make_tuple(0, baby.x, baby.y));
    visited[baby.x][baby.y] = true;

    while (!q.empty()) {
        int dist, x, y;
        tie(dist, x, y) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (!is_area(xx, yy) || visited[xx][yy] || !can_move(xx, yy)) continue;

            visited[xx][yy] = true;
            if (can_eat(xx, yy)) {
                list.push_back(make_tuple(dist + 1, xx, yy)); // 먹을 수 있는 위치 추가
            }
            q.push(make_tuple(dist + 1, xx, yy)); // 이동 가능한 위치 탐색
        }
    }
}

bool eating() {
    if (list.empty()) return false;

    sort(list.begin(), list.end(), compare); // 정렬 기준에 따라 먹을 수 있는 위치 정렬
    int dist, d_x, d_y;
    tie(dist, d_x, d_y) = list[0]; // 가장 가까운 먹이 선택
    res += dist;
    baby.x = d_x;
    baby.y = d_y;
    baby.satiety += 1;

    if (baby.can_level_up()) {
        baby.level += 1;
        baby.satiety = 0;
    }
    area[d_x][d_y] = 0; // 먹은 위치 초기화
    return true;
}

void func() {
    while (true) {
        searching(); // BFS를 통한 먹이 탐색
        if (!eating()) break; // 먹을 수 있는 먹이가 없으면 종료
    }
}

void output() {
    cout << res << '\n';
}

bool can_move(int x, int y) {
    return area[x][y] <= baby.level;
}

bool can_eat(int x, int y) {
    return area[x][y] > 0 && area[x][y] < baby.level;
}

bool is_area(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int c;
            cin >> c;
            area[i][j] = c;
            if (c == 9) {
                baby.x = i;
                baby.y = j;
                area[i][j] = 0; // 아기 상어 위치를 0으로 초기화
            }
        }
    }
    baby.level = 2;
    baby.satiety = 0;
}

// 비교 함수 정의
bool compare(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b); // 거리 기준 정렬
    if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b); // 행 기준 정렬
    return get<2>(a) < get<2>(b);                              // 열 기준 정렬
}
