#include <bits/stdc++.h>

using namespace std;

int t, w;
int res;

vector<int> tree;
int dp[3][1001][32]; // (현재 위치, 진행시간, 움직일 수 있는 횟수)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //여기서의 dp 배열은 (현재 위치, 진행시간, 움직인 횟수) 로 작업.
    //음수 인덱스 방지를 위해, 아무것도 이동 안한 상태를 [1]로 규정.
    res = 0;
    cin>>t>>w;
    for(int i=0; i<t; i++){
        int k; cin>>k;
        tree.push_back(k);
    }
    
    if(tree[0] == 1){
        dp[1][0][1] = 1;
        dp[2][0][2] = 0; 

    }
    else{
        dp[1][0][1] = 0;
        dp[2][0][2] = 1;
    }
    for(int time = 1; time < t; time++){
        for(int move = 1; move <= w+1; move++){
            if(tree[time] == 1){
                dp[1][time][move] = max(dp[1][time-1][move], dp[2][time-1][move-1]) + 1;
                dp[2][time][move] = max(dp[1][time-1][move-1], dp[2][time-1][move]);
            }
            else{
                dp[1][time][move] = max(dp[1][time-1][move], dp[2][time-1][move-1]);
                dp[2][time][move] = max(dp[1][time-1][move-1], dp[2][time-1][move]) + 1;
            }
        }
    }
    int res = 0;
    for(int i=1; i<= w + 1; i++){
        res = max(res, dp[1][t-1][i]);
        res = max(res, dp[2][t-1][i]);
    }
    cout<<res<<'\n';
    return 0;
}

// void input();
// void func();
// void output();

// int main(){
//     input();
//     func();
//     output();
//     return 0;
// }

// int solve(int p, int cur, int coin){
//     if(cur == t) return 0;
//     int &ret = dp[p][cur][coin];
//     if(ret != -1) return ret;

//     ret = 0;
//     //그대로 갔을 때,
//     ret = max(ret, solve(p, cur+1, coin)+((p == tree[cur])? 1 : 0));
//     //바꿨을 때, 
//     if(coin > 0){
//         ret = max(ret, solve((p==1) ? 2 : 1, cur, coin-1)+((p == tree[cur])? 1 : 0));
//     }
//     return ret;
// }

// void func(){
//     int res1 = solve(1, 0, w);
//     int res2 = solve(2, 0, w-1);
//     res = (res1>res2) ? res1:res2;
// }

// void input(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     res = 0;
//     cin>>t>>w;
//     for(int i=0; i<t; i++){
//         int k; cin>>k;
//         tree.push_back(k);
//     }
//     memset(dp, -1, sizeof(dp));
// }

// void output(){
//     cout<<res<<'\n';
// }