#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> num;
vector<pair<int, int>> to_from;
int dp_palin[2001][2001];

void input();
void output();
int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    input();
    output();
    return 0;
}

void output(){
    for(int i=0; i<m; i++){
        int a, b;
        a = to_from[i].first;
        b = to_from[i].second;
        cout<<dp_palin[a][b]<<'\n';
    }
}

void input(){
    cin>>n;
    num.push_back(0);
    for(int i=0; i<n; i++){
        int k; cin>>k;
        num.push_back(k);
    }
    cin>>m;
    for(int i=0; i<m; i++){
        int to, from;
        cin>>to>>from;
        to_from.push_back({to, from});
    }
    for(int i=1; i<=n; i++){
        dp_palin[i][i] = 1;
    }
    for(int i=1; i<n; i++){
        if(i+1 > n) continue;
        if(num[i] == num[i+1]){
            dp_palin[i][i+1] = 1;
        }
    }
    //채워지는 방식이 잘못됨. 채워지는 방향이 계단식이어야 할듯.
    //길이 1, 2인 팰린드롬 판별을 끝난 상태. 이제 길이가 3 이상인 녀석들을 판정해줘야 한다.
    for (int length = 3; length <= n; length++) {
        for (int i = 1; i <= n - length + 1; i++) {
            int j = i + length - 1;
            if (num[i] == num[j] && dp_palin[i + 1][j - 1] == 1) {
                dp_palin[i][j] = 1;
            }
        }
    }
}