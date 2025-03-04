#include <bits/stdc++.h>

using namespace std;

int t, w;
int res;

vector<int> tree;
int dp[3][1001][31]; // (현재 위치, 진행시간, 움직일 수 있는 횟수)

void input();
void func();
void output();

int main(){
    input();
    func();
    output();
    return 0;
}

int solve(int p, int cur, int coin){
    if(cur == t) return 0;
    int &ret = dp[p][cur][coin];
    if(ret != -1) return ret;

    ret = 0;
    //그대로 갔을 때,
    ret = max(ret, solve(p, cur+1, coin)+((p == tree[cur])? 1 : 0));
    //바꿨을 때, (그치만 다음 열매가 바뀌었을 떄, 열려야 의미가 있기에, 분기작업해주기)
    //애초에 현 시점에 열매가 떨어진다면,
    if(coin > 0 && p != tree[cur]){
        ret = max(ret, solve((p==1)?2:1, cur, coin-1));
    }
    return ret;
}

void func(){
    int res1 = solve(1, 0, w);
    int res2 = solve(2, 0, w-1);
    res = (res1>res2) ? res1:res2;
}

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    res = 0;
    cin>>t>>w;
    for(int i=0; i<t; i++){
        int k; cin>>k;
        tree.push_back(k);
    }
    memset(dp, -1, sizeof(dp));
}

void output(){
    cout<<res<<'\n';
}