#include <iostream>
#include <string>
using namespace std;
int c[53][53] = {0, };
void check(int a, int b){
    if(c[a-1][b] == 1){
        c[a-1][b] = 0;
        check(a-1, b);
    }
    if(c[a][b-1] == 1){
        c[a][b-1] = 0;
        check(a, b-1);
    }
    if(c[a+1][b] == 1){
        c[a+1][b] = 0;
        check(a+1, b);
    }
    if(c[a][b+1] == 1){
        c[a][b+1] = 0;
        check(a, b+1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int t; cin>>t;
    for(int T =0; T<t; T++){
        int m, n, k;
        cin>>m>>n>>k;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                c[i][j] = 0;
            }
        }
        for(int i = 0; i<k; i++){
            int q, w; cin>>q>>w;
            c[q+1][w+1] = 1;
        }
        int count = 0;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(c[i][j] == 1){
                    count++;
                    check(i, j);
                }
            }
        }
        cout<<count<<'\n';
    }
    return 0;
}