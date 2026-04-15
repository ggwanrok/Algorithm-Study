#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[36];

ll get_t(int idx){
    if(arr[idx] != -1) return arr[idx];
    ll cur = 0;
    for(int i=0; i<idx; i++){
        cur += get_t(i) * get_t(idx-1-i);
    }
    return arr[idx] = cur;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(arr, -1, sizeof(arr));
    arr[0] = 1;
    int n; cin>>n;
    cout<<get_t(n)<<'\n';
    return 0;
}