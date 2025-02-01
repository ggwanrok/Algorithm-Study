#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct State {
    int Ry, Rx, By, Bx, cnt;
};

int N, M;
vector<vector<char>> board;
bool visited[10][10][10][10];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
State start;

void move_ball(int dir, int &y, int &x, bool &hole, int oy, int ox) {
    while (true) {
        int ny = y + dy[dir], nx = x + dx[dir];
        if (board[ny][nx] == '#' || (ny == oy && nx == ox)) break;
        y = ny;
        x = nx;
        if (board[y][x] == 'O') {
            hole = true;
            y = x = -1; 
            return;
        }
    }
}

void bfs() {
    queue<State> q;
    q.push(start);
    visited[start.Ry][start.Rx][start.By][start.Bx] = true;
    
    while (!q.empty()) {
        State cur = q.front();
        q.pop();
        
        if (cur.cnt >= 10) continue;
        
        for (int i = 0; i < 4; i++) {
            bool redHole = false, blueHole = false;
            int nRy = cur.Ry, nRx = cur.Rx, nBy = cur.By, nBx = cur.Bx;
            
            bool moveFirst = (i == 0 && cur.Ry > cur.By) || (i == 1 && cur.Ry < cur.By) ||
                             (i == 2 && cur.Rx > cur.Bx) || (i == 3 && cur.Rx < cur.Bx);
            
            if (moveFirst) {
                move_ball(i, nBy, nBx, blueHole, nRy, nRx);
                move_ball(i, nRy, nRx, redHole, nBy, nBx);
            } else {
                move_ball(i, nRy, nRx, redHole, nBy, nBx);
                move_ball(i, nBy, nBx, blueHole, nRy, nRx);
            }
            
            if (blueHole) continue;
            if (redHole) {
                cout << cur.cnt + 1 << '\n';
                return;
            }
            
            if (nRy == -1 || nBy == -1) continue; 
            
            if (nRy == nBy && nRx == nBx) {
                if (moveFirst) {
                    nBy -= dy[i];
                    nBx -= dx[i];
                } else {
                    nRy -= dy[i];
                    nRx -= dx[i];
                }
            }
            
            if (!visited[nRy][nRx][nBy][nBx]) {
                visited[nRy][nRx][nBy][nBx] = true;
                q.push({nRy, nRx, nBy, nBx, cur.cnt + 1});
            }
        }
    }
    cout << -1 << '\n';
}

void input() {
    cin >> N >> M;
    board.resize(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {
                start.Ry = i, start.Rx = j;
                board[i][j] = '.';
            } else if (board[i][j] == 'B') {
                start.By = i, start.Bx = j;
                board[i][j] = '.';
            }
        }
    }
    start.cnt = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    input();
    bfs();
    return 0;
}
