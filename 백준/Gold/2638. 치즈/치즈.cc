#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n, m;
int res; // 시간 기록
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int arr[101][101];
int arr_cnt[101][101];
bool air[101][101]; // 외부 공기를 표시할 배열

void mark_external_air();
void melt_cheese();
void input();
void func();
void output();

int main() {
    input();
    func();
    output();
    return 0;
}

void func(){
    while (true) {
        mark_external_air(); // 외부 공기 탐색
        melt_cheese(); // 치즈 녹이기
        res++; // 1초 경과
        bool has_cheese = false;

        // 치즈가 남아있는지 확인
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 1) {
                    has_cheese = true;
                    break;
                }
            }
            if (has_cheese) break;
        }

        if (!has_cheese) break; // 더 이상 치즈가 없으면 종료
    }
}

void mark_external_air() {
    memset(air, false, sizeof(air));
    memset(arr_cnt, 0, sizeof(arr_cnt)); // 매번 arr_cnt 초기화
    queue<pair<int, int>> q;

    // 가장자리에서 외부 공기를 찾기 시작
    for (int i = 0; i < n; i++) {
        if (arr[i][0] == 0 && !air[i][0]) {
            q.push({i, 0});
            air[i][0] = true;
        }
        if (arr[i][m - 1] == 0 && !air[i][m - 1]) {
            q.push({i, m - 1});
            air[i][m - 1] = true;
        }
    }
    for (int j = 0; j < m; j++) {
        if (arr[0][j] == 0 && !air[0][j]) {
            q.push({0, j});
            air[0][j] = true;
        }
        if (arr[n - 1][j] == 0 && !air[n - 1][j]) {
            q.push({n - 1, j});
            air[n - 1][j] = true;
        }
    }

    // BFS로 외부 공기 표시
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx < 0 || xx >= n || yy < 0 || yy >= m || air[xx][yy]) continue;

            if (arr[xx][yy] == 0) {
                q.push({xx, yy}); // 외부 공기 확장
                air[xx][yy] = true;
            } else if (arr[xx][yy] == 1) {
                arr_cnt[xx][yy]++; // 외부 공기와 접촉한 치즈 면 카운트
            }
        }
    }
}

void melt_cheese() {
    // arr_cnt 값이 2 이상인 치즈를 녹임
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1 && arr_cnt[i][j] >= 2) {
                arr[i][j] = 0; // 치즈 녹음
            }
        }
    }
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
}


void output() {
    cout << res << "\n";
}

