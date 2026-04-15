#include <bits/stdc++.h>

using namespace std;

int n;
int w;
vector<pair<int, int>> point;
int dp[1001][1001];
int path[1001][1001];

int distance(const pair<int, int>& a, const pair<int, int>& b);
int solve(int car1, int car2);


void input(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    cin>>w;
    point.push_back({0, 0});
    for(int i=0; i<w; i++){
        int a, b; cin>>a>>b;
        point.push_back(make_pair(a, b));
    }

    memset(dp, -1, sizeof(dp));
}

void func(){
    cout<<solve(0, 0)<<'\n';

    int car1 = 0;
    int car2 = 0;
    for(int i=1; i<=w; i++){
        int next = path[car1][car2];
        cout<<next<<'\n';
        if(next == 1){
            car1 = i;
        }
        else{
            car2 = i;
        }
    }
}


int main(){
    input();
    func();
    return 0;
}


// 두 지점 사이의 거리를 계산하는 함수
int distance(const pair<int, int>& a, const pair<int, int>& b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

// DP 함수 구현
int solve(int car1, int car2) {
    int next = max(car1, car2) + 1;
    if (next > w) return 0;
    if (dp[car1][car2] != -1) return dp[car1][car2];

    // 경찰차 1이 사건 처리하는 경우
    int dist1;
    if (car1 == 0) {
        dist1 = distance({1, 1}, point[next]);
    } else {
        dist1 = distance(point[car1], point[next]);
    }
    int cost1 = solve(next, car2) + dist1;

    // 경찰차 2가 사건 처리하는 경우
    int dist2;
    if (car2 == 0) {
        dist2 = distance({n, n}, point[next]);
    } else {
        dist2 = distance(point[car2], point[next]);
    }
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
