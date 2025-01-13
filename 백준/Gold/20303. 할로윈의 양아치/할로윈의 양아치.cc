#include <bits/stdc++.h>

using namespace std;
/*
유니온 파인드를 통해서.
하나의 덩어리로 인식하게 함.
각 노드의 코스트와 값어치를 계산한다.
각각의 덩어리들을 통해서 k미만의 코스트를 사용한 최대의 값어치 연산 문제.
*/
int n, m, k;

int par[30001];
int cost[30001];
int cnt[30001];

vector<pair<int, int>> bag;

void input();
void func();
// void output();

int find(int);
void union_set(int, int);

int main(){
    input();
    func();
    // output();
    return 0;
}


void func(){

    for(int i=0; i<n; i++){
        find(i); //경로압축 최종 동기화.
    }

    vector<int> par_group;
    par_group.clear();

    for(int i=0; i<n; i++){
        //par[i] == i 인 녀석은 하나의 덩어리로 인식.
        //아닌 녀석은 각 트리의 루트에 candy 값 전달.
        cnt[par[i]]++; //덩어리의 크기를 집계.
        if(par[i] == i){
            par_group.push_back(i);
        }
        else{
            cost[par[i]] += cost[i];
        }
    }

    //cnt 를 무게. cost 를 가치 로 판단하는 배낭문제로의 변환.
    bag.push_back({0, 0});
    for(int i=0; i<par_group.size(); i++){
        bag.push_back({cnt[par_group[i]], cost[par_group[i]]});
    }
    //first 값인 무개를 기준으로 하는 오름차순 정렬.
    sort(bag.begin(), bag.end());
    //dp 2차원 배열을 통한 배낭문제 풀이.
    int dp[bag.size()][k] = {0};
    for(int i=0; i<bag.size(); i++){
        for(int j=0; j<k; j++){
            if(i == 0 || j == 0) dp[i][j] = 0;
            else {
                if(bag[i].first <= j){
                    dp[i][j] = max(dp[i-1][j], bag[i].second + dp[i-1][j-bag[i].first]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    cout<<dp[bag.size()-1][k-1]<<'\n';
}

void union_set(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (a < b) {
            par[b] = a;
        } else {
            par[a] = b;
        }
    }
}

int find(int x){
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}


void input() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int candy;
        cin >> candy;
        cost[i] = candy;
        par[i] = i; // 초기화
        cnt[i] = 0; // 초기화
    }
    for (int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        union_set(n1 - 1, n2 - 1);
    }
}