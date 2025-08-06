#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    int bag = 0;
    int res = 0;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        if(bag + k <= m){
            if(bag == 0) res++;
            bag += k;
        }
        else{
            bag = (k <= m) ? k : 0;
            if(k <= m){
                res++;
            }
        }
    }
    cout<<res<<'\n';
    return 0;
}