#include <bits/stdc++.h>
#define ll long long
#define MAX 9223372036854775800
#define pll_pii pair<long long, pair<int, int>>
using namespace std;
/*
 * 어떤 경로를 통해서 가는지는 궁금하지 않다.
 * 그냥 k이하번의 포장을 통해서 1에서 n까지 이동하는 최단거리가 궁금할 뿐.
 * 그렇다면, 시작점으로부터, 갈 수 있는 가중치가 가장 작은 것부터 꾸준히 업데이트 해주기.
 * 단순하게, 현시점에 코스트가 가장 낮은 녀석이 k번 이하의 도로포장이 된 경우, 해당 경우에서 나가알 수 있는 지점들을 업데이트
 * 이런식으로 업데이트해주다가, 나온 녀석이 n자리 일 경우 정답으로 인정한다.
 * 그렇다면 우선순위 큐를 사용해야겠지.
 */

void input();
void find_to_n();
ll dp[10005][21]; // i 번까지 j개의 포장을 진행할 때의 최솟값
vector<pair<int,int>> connect[10001]; // 출발점을 기준으로, 도작첨과 코스트를 저장한다.
priority_queue<pll_pii> pq; // 우선순위 큐를 이용해서, 다익스트라를 구현

int n, m, k;

int main(){
    input();
    find_to_n();
    return 0;
}

void input(){
    cin>>n>>m>>k;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        connect[a].push_back({b, c});
        connect[b].push_back({a, c});
    }
    for(int i=1; i<=n ; i++){
        for(int j=0; j<=20; j++){
            dp[i][j] = MAX;
        }
    }
}

void find_to_n(){
    dp[1][0] = 0; // 시작점은 확정
    pq.push({0, {1, 0}});
    // 시작점으로부터 갈 수 있는 길에서, 최저점을 업데이트 해주는 내용.
    while (!pq.empty()){
        pll_pii front = pq.top();
        long long value = -front.first;
        int cost_from = front.second.first;
        int cost_to = front.second.second;
        pq.pop();
        // 값을 역수로 취급하여, 우선순위 큐에서, 최소힙처럼 사용할 수 있다.
        if(value > dp[cost_from][cost_to]) continue;
        for(int i=0; i<connect[cost_from].size(); i++){
            int x = connect[cost_from][i].first;
            int len = connect[cost_from][i].second;
            if(cost_to < k){
                if(dp[x][cost_to+1] > value){
                    dp[x][cost_to+1] = value;
                    pq.push({-dp[x][cost_to+1], {x, cost_to+1}});
                }
            }
            if(dp[x][cost_to] > value + len){
                dp[x][cost_to] = value + len;
                pq.push({-dp[x][cost_to], {x, cost_to}});
            }
        }
    }
    ll res = MAX;
    for(int i=0; i<=k; i++){
        res = res < dp[n][i] ? res : dp[n][i];
    }
    cout<<res<<'\n';
}