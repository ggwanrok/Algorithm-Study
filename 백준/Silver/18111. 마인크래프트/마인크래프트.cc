#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m;
ll b;
ll res_floor;
ll res_time = LLONG_MAX;
int area[501][501];

void input();
void func();
void output();

int main() {
    input();
    func();
    output();
    return 0;
}

void output() {
    cout << res_time << ' ' << res_floor << '\n';
}

void func() {
    // 1. 최대 층수 구하기
    int max_floor = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            max_floor = max(max_floor, area[i][j]);
        }
    }

    // 2. 최댓값부터 0까지 탐색
    for (int floor = max_floor; floor >= 0; floor--) {
        ll cur_time = 0;
        ll cur_block = b; // 초기 블록 수
        bool can_do = true;

        // 2-1. 블록 제거 (여유 블록 확보)
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                int diff = area[row][col] - floor;
                if (diff > 0) {
                    cur_block += diff;
                    cur_time += (ll)diff * 2; // 제거는 2초
                }
            }
        }

        // 2-2. 블록 추가 (부족한 블록 채우기)
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                int diff = floor - area[row][col];
                if (diff > 0) {
                    if (cur_block >= diff) {
                        cur_block -= diff;
                        cur_time += diff; // 추가는 1초
                    } else {
                        can_do = false; // 블록 부족
                        break;
                    }
                }
            }
            if (!can_do) break;
        }

        // 3. 최적 시간 및 층 업데이트
        if (can_do && cur_time < res_time) {
            res_time = cur_time;
            res_floor = floor;
        }
    }
}

void input() {
    cin >> n >> m >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> area[i][j];
        }
    }
}
