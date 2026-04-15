#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a_sum[1005];
ll b_sum[1005];
ll t, n, m;
ll res = 0;
map<ll, ll> b_b; //(해당 값이, 얼마나 존재하는가) 를 저장함

void input();
void func();
void output();

int main(){
    input();
    func();
    output();
    return 0;
}

void func(){
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            int cur_a = a_sum[j] - a_sum[i-1];
            res += b_b[t-cur_a];
        }   
    }
}

void input(){
    cin>>t;
    a_sum[0] = b_sum[0] = 0;
    cin>>n;
    for(int i=1; i<=n; i++){
        ll val;
        cin>>val;
        a_sum[i] = a_sum[i-1] + val; 
    }
    cin>>m;
    for(int i=1; i<=m; i++){
        ll val;
        cin>>val;
        b_sum[i] = b_sum[i-1] + val;
    }
    for(int i=1; i<=m; i++){
        for(int j=i; j<=m; j++){
            b_b[b_sum[j]-b_sum[i-1]]++; //각 부분배열은 길이가 적어도 1 이상이라서 이런식으로 사용함.
        }
    }
}

void output(){
    cout<<res<<'\n';
}