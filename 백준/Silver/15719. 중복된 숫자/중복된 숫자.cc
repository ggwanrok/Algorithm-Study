#include <bits/stdc++.h>

using namespace std;

int arr[10000001];
int res;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n;
    while(n--){
        int k; cin>>k;
        if(arr[k] != 0){
            cout<<k<<'\n';
            break;
        }
        arr[k]++;
    }
    return 0;
}