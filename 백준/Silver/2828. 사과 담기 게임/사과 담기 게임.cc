#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    int q;
    cin>>q;


    int cur = 1;
    int res = 0;
    for(int i=1; i<=q; i++){
        int k; cin>>k;
        if(k >= cur && k <= cur + m -1){
            continue;
        }
        if(k < cur){
            int move = cur - k;
            cur -= move;
            res += move;
        }
        else{
            int move = k - (cur + m - 1);
            cur += move;
            res += move;
        }
    }
    cout<<res<<'\n';
    return 0;
}