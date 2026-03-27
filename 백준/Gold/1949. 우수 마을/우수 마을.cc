#include <bits/stdc++.h>

using namespace std;

/*
트리구조인 만큼 싸이클은 없다
퐁당퐁당구조

비우수 마을은 반드시 하나 이상의 우수마을과 겹쳐있다.

노드 하나를 잡고
현시점. 얘가 우수마을일 때의 최대구조, 아닐 때의 최대구조 를 봐야하나?

이어진 이미 방문저치된 놈들을 기준으로 보면 된다.
이제 방문한 녀석 하나를 잡아.
얘가 우수이려면 : 이전에 이어온 놈들이 우수마을이 아닐 때의 값의 합계 + 해당 마을 코스트값
얘가 우수마을이 아니려면 : 각 녀석들이 우수마을일 때를 하나씩 기점으로 잡고 나머지 마을들이 우수마을이든 아니든 가장 큰 값을 가지게 하는 경우와 합산함

tree구조라 뭘 잡고해도 상관없음

-- 오류 : 해당 구조는 트리가 여러갈래로 쪼개질 때, 결국 서브트리의 결과값 한산 반영이 안될 수 있는 구조이다.

그래서 뭘 해야하냐.
서브트리가 있다면 전부 재귀를 돌린 뒤에 반영하는 재귀 탐색이 도입되어야 할 것 같다.
*/

int n;
vector<int> town_cost;
vector<vector<int>> bridge;
vector<int> is_visited;
vector<vector<int>> dp;

void set_dp(int k, int pre){
    for(auto iter : bridge[k]){
        if(is_visited[iter] == 0){
            is_visited[iter] = 1;
            set_dp(iter, k);
        }
    }
    dp[k][0] = town_cost[k];
    dp[k][1] = 0;
    for(auto iter : bridge[k]){
        if(iter == pre) continue;
        dp[k][0] += dp[iter][1];
        dp[k][1] += max(dp[iter][0], dp[iter][1]);
        // int cur_nice_town = dp[iter][0];
        // for(auto n_iter : bridge[k]){
        //     if(iter == n_iter) continue;
        //     cur_nice_town += max(dp[n_iter][0], dp[n_iter][1]);
        // }
        // dp[k][1] = max(dp[k][1], cur_nice_town);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    bridge.resize(n);
    is_visited.resize(n, 0);
    dp.resize(n, vector<int>(2, 0));
    for(int i=0; i<n; i++){
        int k; cin>>k;
        town_cost.push_back(k);
    }
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        a--; b--;
        bridge[a].push_back(b);
        bridge[b].push_back(a);
    }

    is_visited[0] = 1;
    set_dp(0, -1);
    cout<<max(dp[0][0], dp[0][1])<<'\n';
    //주위 이웃이 모두 visited 인 놈까지 내려가서 해당 녀석의 dp배열을 업데이트해준다. 돌아와선, 해당 값을 반영해준다.


    // queue<int> q;
    // q.push(0);
    // while(!q.empty()){
    //     int iter = q.front();
    //     q.pop();
    //     for(auto cur : bridge[iter]){
    //         //이어진 부분들
    //         if(is_visited[cur] != 0) continue;
    //         //방문 안했던 놈을 기준으로 이미 방문처리된 인근 동선을 따라서 체크할 것.
    //         dp[cur][0] = town_cost[cur];
    //         for(auto pre : bridge[cur]){
    //             if(is_visited[pre] == 0) continue;
    //             //[cur][0] : cur이 우수일 때 
    //             dp[cur][0] += dp[pre][1];
    //             // [cur][1] : cur이 우수가 아닐 때
    //             int cur_value = dp[pre][0];
    //             for(auto n_pre : bridge[cur]){
    //                 if(is_visited[n_pre] == 0 || pre == n_pre) continue;
    //                 //pre를 우수마을이었다고 할 때, n_pre들이 우수이든 아니든 나올 수 있는 최댓값을 넣어주기.
    //                 cur_value += max(dp[n_pre][0], dp[n_pre][1]);
    //             }
    //             dp[cur][1] = max(dp[cur][1], cur_value);
    //         }
    //         is_visited[cur] = 1;
    //         q.push(cur);
    //     }
    // }
    // int res = 0;
    // for(int i=0; i<n; i++){
    //     res = max(res, max(dp[i][0], dp[i][1]));
    // }
    // cout<<res<<'\n';
    return 0;
}