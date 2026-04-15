#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int main(){
    cin>>n>>m;
    int a[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
    cin>>m;
    cin>>k;
    int b[m][k];
    for(int i=0; i<m; i++){
        for(int j=0; j<k; j++){
            cin>>b[i][j];
        }
    }
    int res[n][k];
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            res[i][j] = 0;
            for(int c = 0; c < m; c++){
                res[i][j] += a[i][c] * b[c][j];
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            cout<<res[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}