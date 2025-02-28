#include <bits/stdc++.h>
using namespace std;

int n, w;
vector<pair<int, int>> point;
int dp[1001][1001]; // DP 배열
int path[1001][1001]; // 이동 경로 저장 배열

// 두 지점 사이의 거리 계산
int get_dist(const pair<int, int>& a, const pair<int, int>& b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

// DP 함수 구현
int solve(int car1, int car2) {
    int next = max(car1, car2) + 1; // 다음 처리할 사건 번호
    if (next > w) return 0; // 모든 사건 처리 완료 시

    if (dp[car1][car2] != -1) return dp[car1][car2]; // 이미 계산된 값 리턴

    // 1번 경찰차가 처리하는 경우
    int dist1 = (car1 == 0) ? get_dist({1, 1}, point[next]) : get_dist(point[car1], point[next]);
    int cost1 = solve(next, car2) + dist1;

    // 2번 경찰차가 처리하는 경우
    int dist2 = (car2 == 0) ? get_dist({n, n}, point[next]) : get_dist(point[car2], point[next]);
    int cost2 = solve(car1, next) + dist2;

    // 최소값 선택 및 경로 저장
    if (cost1 < cost2) {
        dp[car1][car2] = cost1;
        path[car1][car2] = 1;
    } else {
        dp[car1][car2] = cost2;
        path[car1][car2] = 2;
    }

    return dp[car1][car2];
}

// 입력 함수
void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> w;
    point.push_back({0, 0}); // 인덱스를 1부터 사용하기 위해 더미 데이터 추가

    for (int i = 0; i < w; i++) {
        int a, b; 
        cin >> a >> b;
        point.push_back({a, b});
    }

    memset(dp, -1, sizeof(dp)); // DP 배열 초기화
}

// 경로 출력 함수
void func() {
    cout << solve(0, 0) << '\n'; // 최소 거리 출력

    int car1 = 0, car2 = 0;
    for (int i = 1; i <= w; i++) {
        int next = path[car1][car2]; // 현재 위치에서 어떤 경찰차가 이동했는지 확인
        cout << next << '\n';

        if (next == 1) car1 = i; // 1번 경찰차가 이동한 경우
        else car2 = i; // 2번 경찰차가 이동한 경우
    }
}

int main() {
    input();
    func();
    return 0;
}
