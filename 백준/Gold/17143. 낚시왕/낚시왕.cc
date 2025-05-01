#include <bits/stdc++.h>

using namespace std;

struct shark{
    int is_alive;
    int ro;
    int co;
    int sp;
    int di;
    int wi;
    shark(int is_alive, int ro, int co, int sp, int di, int wi) : is_alive(is_alive), ro(ro), co(co), sp(sp), di(di), wi(wi) {}
};

int arr[105][105];
int r, c;
int m;

int fisher;
int res;

vector<shark> shark_list;

//위 아래 오른 왼
int dx[5] = {0, 0, 0, 1, -1}; // 열 이동
int dy[5] = {0, -1, 1, 0, 0}; // 행 이동

/*
1. 낚시꾼을 이동시킨다.
2. 잡을 수 있는 상어를 파악한 뒤 잡는다.
3. 상어를 이동시킨다.
4. 겹치는 상어에 대한 제거작업을 해준다.
*/

void input();
void func();

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    func();
    
    return 0;
}

void func() {
    for (fisher = 1; fisher <= c; fisher++) {

        // 1. 낚시 (현재 열에서 가장 위에 있는 상어 잡기)
        for (int row = 1; row <= r; row++) {
            int idx = arr[row][fisher];
            if (idx != 0 && shark_list[idx].is_alive) {
                shark_list[idx].is_alive = 0;
                res += shark_list[idx].wi;
                arr[row][fisher] = 0;
                break;
            }
        }

        // 2. temp 배열 초기화
        int temp[105][105] = {0};

        // 3. 상어 이동
        for (int i = 1; i <= m; i++) {
            if (!shark_list[i].is_alive) continue;

            shark& s = shark_list[i];
            int y = s.ro, x = s.co, d = s.di, v = s.sp;

            // 속도 최적화
            if (d == 1 || d == 2) v %= (2 * (r - 1));
            else v %= (2 * (c - 1));

            int nx = x, ny = y;

            while (v--) {
                int ty = ny + dy[d];
                int tx = nx + dx[d];

                // 벽에 부딪히면 방향 반전
                if (ty < 1 || ty > r || tx < 1 || tx > c) {
                    if (d == 1) d = 2;
                    else if (d == 2) d = 1;
                    else if (d == 3) d = 4;
                    else if (d == 4) d = 3;
                    ty = ny + dy[d];
                    tx = nx + dx[d];
                }

                ny = ty;
                nx = tx;
            }

            // 위치, 방향 갱신
            s.ro = ny;
            s.co = nx;
            s.di = d;

            // 겹치는 상어 처리
            if (temp[ny][nx] == 0) {
                temp[ny][nx] = i;
            } else {
                int other = temp[ny][nx];
                if (shark_list[other].wi > s.wi) {
                    s.is_alive = 0;
                } else {
                    shark_list[other].is_alive = 0;
                    temp[ny][nx] = i;
                }
            }
        }

        // 4. arr 갱신
        memset(arr, 0, sizeof(arr));
        for (int i = 1; i <= m; i++) {
            if (shark_list[i].is_alive) {
                arr[shark_list[i].ro][shark_list[i].co] = i;
            }
        }
    }

    // 결과 출력
    cout << res << '\n';
}

void input(){
    cin>>r>>c>>m;
    shark_list.push_back(shark(0, 0, 0, 0, 0, 0));
    for(int rec = 1; rec <= m; rec++){
        int row, col, speed, dist, wei;
        cin>>row>>col>>speed>>dist>>wei;
        //각 상어에게 rec 의 번호를 부여
        //arr 판에는 rec 번호로 넣어주고
        //각 번호에 따른 관리를 할 shark 객체 관리
        arr[row][col] = rec;
        shark_list.push_back(shark(1, row, col, speed, dist, wei));
    }
}
