#include <bits/stdc++.h>

using namespace std;

int r, c, res;
set<char> keys;
char home[101][101];
bool visited[101][101];
string pre_key;
queue<pair<int, int>> q;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void input();
void bfs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while (tc--) {
        input();
        bfs();
        cout << res << '\n';
    }

    return 0;
}

void input() {
    cin >> r >> c;
    res = 0;

    // 배열 초기화
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            home[i][j] = ' ';
            visited[i][j] = false;
        }
    }

    // 지도 입력
    for (int i = 0; i < r; i++) {
        string home_r;
        cin >> home_r;
        for (int j = 0; j < c; j++) {
            home[i][j] = home_r[j];
        }
    }

    // 기존 열쇠 입력
    keys.clear();
    cin >> pre_key;
    if (pre_key != "0") {
        for (char key : pre_key) {
            keys.insert(key);
        }
    }
}

void bfs() {
    queue<pair<int, int>> wait[26];  // 열쇠가 없어서 대기하는 문 위치 저장

    // 테두리에서 시작 가능한 지점 찾기 (BFS 내부와 동일한 방식 적용)
    for (int i = 0; i < c; i++) {
        // 위쪽 테두리
        if (home[0][i] != '*') {
            if (home[0][i] >= 'A' && home[0][i] <= 'Z' && keys.find(tolower(home[0][i])) == keys.end()) {
                wait[home[0][i] - 'A'].push({0, i});  // 열쇠 없으면 대기
            } else {
                q.push({0, i});
            }
        }
        // 아래쪽 테두리
        if (home[r - 1][i] != '*') {
            if (home[r - 1][i] >= 'A' && home[r - 1][i] <= 'Z' && keys.find(tolower(home[r - 1][i])) == keys.end()) {
                wait[home[r - 1][i] - 'A'].push({r - 1, i});  
            } else {
                q.push({r - 1, i});
            }
        }
    }
    for (int i = 1; i < r - 1; i++) {
        // 왼쪽 테두리
        if (home[i][0] != '*') {
            if (home[i][0] >= 'A' && home[i][0] <= 'Z' && keys.find(tolower(home[i][0])) == keys.end()) {
                wait[home[i][0] - 'A'].push({i, 0});
            } else {
                q.push({i, 0});
            }
        }
        // 오른쪽 테두리
        if (home[i][c - 1] != '*') {
            if (home[i][c - 1] >= 'A' && home[i][c - 1] <= 'Z' && keys.find(tolower(home[i][c - 1])) == keys.end()) {
                wait[home[i][c - 1] - 'A'].push({i, c - 1});
            } else {
                q.push({i, c - 1});
            }
        }
    }

    // BFS 탐색 시작
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (visited[x][y]) continue;
        visited[x][y] = true;

        // 열쇠를 발견하면 획득
        if (home[x][y] >= 'a' && home[x][y] <= 'z') {
            char new_key = home[x][y];
            if (keys.find(new_key) == keys.end()) {
                keys.insert(new_key);

                // 새로운 열쇠를 얻었으므로 대기 중인 문들을 열어줌
                while (!wait[new_key - 'a'].empty()) {
                    q.push(wait[new_key - 'a'].front());
                    wait[new_key - 'a'].pop();
                }
            }
        }

        // 문서 획득
        if (home[x][y] == '$') {
            res++;
        }

        // 4방향 탐색
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx < 0 || xx >= r || yy < 0 || yy >= c || visited[xx][yy] || home[xx][yy] == '*') continue;

            // 문(`A`~`Z`)을 만났을 때 열쇠가 없으면 대기
            if (home[xx][yy] >= 'A' && home[xx][yy] <= 'Z' && keys.find(tolower(home[xx][yy])) == keys.end()) {
                wait[home[xx][yy] - 'A'].push({xx, yy});
                continue;
            }

            // 이동 가능하면 큐에 추가
            q.push({xx, yy});
        }
    }
}
