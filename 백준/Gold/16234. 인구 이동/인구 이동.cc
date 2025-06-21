// start : 01 : 33
/*
드는 생각.
각 픽셀은 본인을 루트로 시작한다.
순차적 탐색시에, 루트가 다르다면 유니온-파인드를 진행해준다.
그리고 해당 루트의 합산값. 평균값. 갯수를 변수로 관리해준다.

*/
#include <bits/stdc++.h>
using namespace std;

int n, l_g, h_g;
int arr[51][51];
pair<int, int> root[51][51]; // 루트 좌표를 저장
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

pair<int, int> find(pair<int, int> p) {
    int x = p.first, y = p.second;
    if (root[x][y] == make_pair(x, y)) return {x, y};
    return root[x][y] = find(root[x][y]);
}

void unite(pair<int, int> a, pair<int, int> b) {
    pair<int, int> ra = find(a);
    pair<int, int> rb = find(b);
    if (ra != rb) root[rb.first][rb.second] = ra;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> l_g >> h_g;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            root[i][j] = {i, j}; // 각 픽셀을 루트로 시작
        }

    int days = 0;

    while (true) {
        bool moved = false;

        // 루트 초기화 (매일 새롭게)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                root[i][j] = {i, j};

        // 유니온 과정
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                for (int dir = 0; dir < 4; dir++) {
                    int ni = i + dx[dir], nj = j + dy[dir];
                    if (ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
                    int diff = abs(arr[i][j] - arr[ni][nj]);
                    if (diff >= l_g && diff <= h_g) {
                        unite({i, j}, {ni, nj});
                        moved = true;
                    }
                }
            }

        if (!moved) break;

        // 루트별로 그룹 정보 집계
        map<pair<int, int>, vector<pair<int, int>>> groups;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                groups[find({i, j})].push_back({i, j});

        // 인구 재분배
        for (auto &g : groups) {
            int total = 0;
            for (auto &cell : g.second)
                total += arr[cell.first][cell.second];
            int avg = total / g.second.size();
            for (auto &cell : g.second)
                arr[cell.first][cell.second] = avg;
        }

        days++;
    }

    cout << days << '\n';
    return 0;
}