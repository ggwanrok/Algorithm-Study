#include <bits/stdc++.h>
using namespace std;

int n, m, h;
int zero_cnt = 0;
int res = 0;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};

int ground[101][101][101];
int visited[101][101][101];

void input();
void func();

int main() {
    input();
    func();
    if (zero_cnt == 0) 
        cout << res << '\n';
    else 
        cout << -1 << '\n';

    return 0;
}

void func() {
    queue<pair<pair<int, int>, int>> q;

    for (int z = 0; z < h; z++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (ground[x][y][z] == 1) {
                    visited[x][y][z] = 1;
                    q.push({{x, y}, z});
                }
            }
        }
    }

    while (!q.empty()) {
        int xx = q.front().first.first;
        int yy = q.front().first.second;
        int zz = q.front().second;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int xxx = xx + dx[i];
            int yyy = yy + dy[i];
            int zzz = zz + dh[i];

            if (xxx < 0 || yyy < 0 || zzz < 0 || xxx >= n || yyy >= m || zzz >= h) continue;
            if (ground[xxx][yyy][zzz] != 0) continue;
            if (visited[xxx][yyy][zzz] != 0) continue;

            visited[xxx][yyy][zzz] = 1;
            zero_cnt--;
            ground[xxx][yyy][zzz] = ground[xx][yy][zz] + 1;
            q.push({{xxx, yyy}, zzz});
            res = max(res, ground[xxx][yyy][zzz] - 1);
        }
    }
}

void input() {
    cin >> m >> n >> h;
    for (int hh = 0; hh < h; hh++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> ground[i][j][hh];
                if (ground[i][j][hh] == 0) 
                    zero_cnt++;
            }
        }
    }
}
