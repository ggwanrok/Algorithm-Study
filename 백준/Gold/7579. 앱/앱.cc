#include <bits/stdc++.h>

using namespace std;

int M;
int new_M; // 이 값 이하로 최대 cost를 선택하는 배낭 문제로 변형.
// 최대로 선택하여 모든 cost들의 합에서 해당 cost를 빼주면 답.
int cost_sum;
vector<pair<int, int>> v;

bool compare(pair<int, int>, pair<int, int>);
void input();
int func();
void output();


int main(){
    input();
    output();
    return 0;
}

int func(){
    vector<int> dp(new_M+1, 0);
    for(int i=0; i<v.size(); i++){
        int cost = v[i].first;
        int wei = v[i].second;

        for(int w = new_M; w >= wei; w--){
            dp[w] = max(dp[w-wei] + cost, dp[w]);
        }
    }
    return dp[new_M];
}


void output(){
    cout<<cost_sum - func()<<'\n';
}

void input(){
    int n; cin>>n;
    int m_sum=0;
    vector<int> v_1;
    vector<int> v_2;
    cin>>M;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        v_2.push_back(k);
        m_sum += k;
    }
    for(int i=0; i<n; i++){
        int k; cin>>k;
        v_1.push_back(k);
        cost_sum += k;
    }
    for(int i=0; i<n; i++){
        v.push_back({v_1[i], v_2[i]});
    }
    new_M = m_sum - M;
    sort(v.begin(), v.end(), compare);
}


bool compare(pair<int, int> a, pair<int, int> b){
     return (double)a.first / a.second > (double)b.first / b.second;
}