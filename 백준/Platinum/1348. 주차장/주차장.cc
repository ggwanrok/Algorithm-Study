#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

void input();
bool is_inside(int, int);
void bfs(int);
bool dfs(int, int, const vector<vector<int>>&);

int r, c;
char parking[51][51];
int dist[51][51];
vector<pair<int, int>> car;
int car_to[1000];
vector<pair<int, int>> park;
int park_from[1000];
vector<vector<int>> way;
bool visited[1000];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    input();

    way.resize(car.size());
    vector<vector<int>> car_to_park_dist(car.size(), vector<int>(park.size(), INF));

    for (int i = 0; i < car.size(); ++i) {
        fill(&dist[0][0], &dist[0][0] + 51 * 51, INF);
        bfs(i);
        for (int j = 0; j < park.size(); ++j) {
            auto [px, py] = park[j];
            if (dist[px][py] != INF) {
                car_to_park_dist[i][j] = dist[px][py];
                way[i].push_back(j);
            }
        }
    }

    int left = 0, right = r * c, answer = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        memset(car_to, -1, sizeof(car_to));
        memset(park_from, -1, sizeof(park_from));

        int match_count = 0;
        for (int i = 0; i < car.size(); ++i) {
            memset(visited, false, sizeof(visited));
            if (dfs(i, mid, car_to_park_dist)) {
                match_count++;
            }
        }

        if (match_count == car.size()) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}

void input() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string input_str;
        cin >> input_str;
        for (int j = 0; j < c; j++) {
            parking[i][j] = input_str[j];
            if (parking[i][j] == 'C') {
                car.push_back({i, j});
            }
            if (parking[i][j] == 'P') {
                park.push_back({i, j});
            }
        }
    }
}

bool is_inside(int x, int y) {
    return x >= 0 && x < r && y >= 0 && y < c;
}

void bfs(int car_idx) {
    queue<pair<int, int>> q;
    pair<int, int> cur_pair = car[car_idx];
    int cur_x = cur_pair.first;
    int cur_y = cur_pair.second;
    dist[cur_x][cur_y] = 0;
    q.push(cur_pair);

    while (!q.empty()) {
        pair<int, int> bfs_pair = q.front();
        int x = bfs_pair.first;
        int y = bfs_pair.second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (is_inside(nx, ny) && parking[nx][ny] != 'X' && dist[nx][ny] == INF) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

bool dfs(int car_idx, int limit, const vector<vector<int>>& car_to_park_dist) {
    for (int park_id : way[car_idx]) {
        if (car_to_park_dist[car_idx][park_id] > limit) continue;  // Check if the distance to park is within the limit
        if (visited[park_id]) continue;
        visited[park_id] = true;

        if (park_from[park_id] == -1 || dfs(park_from[park_id], limit, car_to_park_dist)) {
            car_to[car_idx] = park_id;
            park_from[park_id] = car_idx;
            return true;
        }
    }
    return false;
}
