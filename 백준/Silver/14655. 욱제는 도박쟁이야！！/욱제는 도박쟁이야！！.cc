#include <bits/stdc++.h>

using namespace std;

vector<int> coins;
int n;

int main(){
    cin>>n;
    for(int loop = 0; loop < n; loop++){
        int k; cin>>k;
        coins.push_back(abs(k));
    }
    for(int loop = 0; loop < n; loop++){
        int k; cin>>k;
    }
    sort(coins.begin(), coins.end());

    int val_1, val_2;
    val_1 = val_2 = 0;
    for(int coin :coins){
        val_1 += coin;
    }
    cout<<val_1*2<<'\n';
    return 0;
}