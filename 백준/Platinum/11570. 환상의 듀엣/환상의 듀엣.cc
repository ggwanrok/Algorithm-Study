#include <bits/stdc++.h>

using namespace std;

/*
중간값을 가지고 하는 것에는 논리 오류가 있네.
1~18라서 중간 9 설정.
-> 9 1 2 1 2 1 (이거 반복)..
-> 10
이렇게 된 시점에, 
8이 나오면
10에서 가는 것이 맞는 것이 반례.
*/


int n, res;
vector<int> sound;
int dp[2001][2001];

void input();
void func();
void output();

int dp_func(int idx_1, int idx_2){
    if (idx_1 < idx_2) swap(idx_1, idx_2); // 항상 idx_1 > idx_2 유지

    int &res_dp = dp[idx_1][idx_2];  
    if (res_dp != -1) return res_dp;

    int next = idx_1 + 1; // 다음 선택할 인덱스
    if(next == n + 1) return 0;

    //idx_1 을 마지막으로 선택한 녀석 -> next 를 선택한 경우
    res_dp = dp_func(next, idx_2) + abs(sound[idx_1] - sound[next]);

    //idx_2 를 마지막으로 선택한 녀석 -> next 를 선택한 경우
    if(idx_2 == 0){ // 잉여인간이 최초로 선택한 경우
        res_dp = min(res_dp, dp_func(idx_1, next));
    }
    else{ // 최초선택이 아닐 경우
        res_dp = min(res_dp, dp_func(idx_1, next) + abs(sound[idx_2] - sound[next]));
    }
    return res_dp;
}

int main(){
    input();
    func();
    output();
    return 0;
}

void output(){
    cout<<res<<'\n';
}

void func(){
    res = dp_func(1, 0); //첫번째 요소만 선택한 뒤, 다른 녀석들은 선택하지 않음.
}   


void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    res = 0;
    sound.push_back(0); //아무것도 선택하지 않은 시점 고려

    for(int i=1; i<=n; i++){
        int k; cin>>k;
        sound.push_back(k);
    } 
    memset(dp, -1, sizeof(dp));
}