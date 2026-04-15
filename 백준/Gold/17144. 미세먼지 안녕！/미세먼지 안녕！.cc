#include <iostream>
#include <cstring>
using namespace std;

int r, c, t;
int ori_arr[51][51]; // 현재 상태 배열
int sub_arr[51][51]; // 확산 후 임시 상태 배열
pair<int, int> cleaner_1; // 위쪽 공기청정기 위치
pair<int, int> cleaner_2; // 아래쪽 공기청정기 위치

void input();
void func();
void func_1();
void func_2();
void spread(int, int, int);

int main(){
    input();
    func();
    return 0;
}

void input(){
    cin >> r >> c >> t;
    cleaner_1 = {-1, -1}; // 초기 클리너 위치 설정
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> ori_arr[i][j];
            if (ori_arr[i][j] == -1) { // 공기청정기 위치 저장
                if (cleaner_1.first == -1) {
                    cleaner_1 = {i, j}; // 첫 번째 클리너 위치
                } else {
                    cleaner_2 = {i, j}; // 두 번째 클리너 위치
                }
            }
        }
    }
}

void func(){
    while (t--) {
        func_1(); // 미세먼지 확산
        func_2(); // 공기청정기 작동
    }
    int res = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (ori_arr[i][j] > 0) { // 공기청정기 위치(-1)는 제외하고 계산
                res += ori_arr[i][j];
            }
        }
    }
    cout << res << '\n';
}

// 미세먼지 확산 함수
void func_1(){
    memset(sub_arr, 0, sizeof(sub_arr)); // sub_arr 초기화

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (ori_arr[i][j] > 0) { // 미세먼지가 있는 위치에서 확산 수행
                spread(i, j, ori_arr[i][j]);
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ori_arr[i][j] += sub_arr[i][j]; // 확산 결과 반영
        }
    }
}

// 확산 메커니즘
void spread(int i, int j, int value) {
    if (value < 5) return; // 확산할 수 없으면 종료

    int spread_value = value / 5; // 각 방향으로 확산될 양
    int spread_cnt = 0; // 확산이 일어난 방향의 수

    // 상, 우, 하, 좌 순서로 확산
    if (i - 1 >= 0 && ori_arr[i - 1][j] != -1) { // 위로 확산
        sub_arr[i - 1][j] += spread_value;
        spread_cnt++;
    }
    if (j + 1 < c && ori_arr[i][j + 1] != -1) { // 오른쪽으로 확산
        sub_arr[i][j + 1] += spread_value;
        spread_cnt++;
    }
    if (i + 1 < r && ori_arr[i + 1][j] != -1) { // 아래로 확산
        sub_arr[i + 1][j] += spread_value;
        spread_cnt++;
    }
    if (j - 1 >= 0 && ori_arr[i][j - 1] != -1) { // 왼쪽으로 확산
        sub_arr[i][j - 1] += spread_value;
        spread_cnt++;
    }

    sub_arr[i][j] -= spread_value * spread_cnt; // 확산된 만큼 현재 위치에서 차감
}

// 공기청정기 작동 함수
void func_2(){
    // 위쪽 공기청정기: 반시계 방향 회전
    int x = cleaner_1.first;
    int y = cleaner_1.second;

    // 위쪽 공기청정기의 반시계 방향 공기 흐름
    for (int i = x - 1; i > 0; i--) ori_arr[i][y] = ori_arr[i - 1][y]; // 아래로 이동
    for (int j = 0; j < c - 1; j++) ori_arr[0][j] = ori_arr[0][j + 1]; // 왼쪽으로 이동
    for (int i = 0; i < x; i++) ori_arr[i][c - 1] = ori_arr[i + 1][c - 1]; // 위로 이동
    for (int j = c - 1; j > 1; j--) ori_arr[x][j] = ori_arr[x][j - 1]; // 오른쪽으로 이동
    ori_arr[x][1] = 0; // 공기청정기에서 나오는 부분은 0
    ori_arr[x][y] = -1;
    // 아래쪽 공기청정기: 시계 방향 회전
    x = cleaner_2.first;
    y = cleaner_2.second;

    // 아래쪽 공기청정기의 시계 방향 공기 흐름
    for (int i = x + 1; i < r - 1; i++) ori_arr[i][y] = ori_arr[i + 1][y]; // 위로 이동
    for (int j = 0; j < c - 1; j++) ori_arr[r - 1][j] = ori_arr[r - 1][j + 1]; // 왼쪽으로 이동
    for (int i = r - 1; i > x; i--) ori_arr[i][c - 1] = ori_arr[i - 1][c - 1]; // 아래로 이동
    for (int j = c - 1; j > 1; j--) ori_arr[x][j] = ori_arr[x][j - 1]; // 오른쪽으로 이동
    ori_arr[x][1] = 0; // 공기청정기에서 나오는 부분은 0
    ori_arr[x][y] = -1;
}
