#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m; //세로줄 가로줄

    if(n == 1) cout<<1<<'\n';
    else if(n == 2){
        cout<<min(4, (m-1)/2+1)<<'\n';
    }
    else if(n >= 3 && m < 7) {
        cout<<min(4, m);
    }
    else{
        cout<<m-2<<'\n';
    }
    
    

    
}