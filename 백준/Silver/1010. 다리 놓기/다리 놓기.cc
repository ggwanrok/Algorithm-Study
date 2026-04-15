#include <iostream>

using namespace std;

int memory[31][31];

int combination(int n, int r){
    if(n == r || r == 0){
        return 1;
    }
    else{
        if(memory[n][r] != 0) return memory[n][r];

        return memory[n][r] = combination(n-1, r-1) + combination(n-1, r);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--){
        int a, b;
        cin>>a>>b;
        if(a == b){
            cout<<1<<'\n';
            continue;
        }
        int c = b - a;
        //bCc를 진행해야 함.
        cout<<combination(b, c)<<'\n';
    }
}