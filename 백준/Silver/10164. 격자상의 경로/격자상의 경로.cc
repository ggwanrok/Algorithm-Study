#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int arr[20][20];

int main(){
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>k;
    k = (k > 0) ? k-1 : k;
    int k_c = k / m;
    int k_r = k % m;

    for(int i=0; i<15; i++){
        arr[i][0] = 1;
        arr[0][i] = 1;
    }

    for(int i=1; i<15; i++){
        for(int j=1; j<15; j++){
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }
    cout<<arr[k_c][k_r] * arr[n-1-k_c][m-1-k_r]<<'\n';
    return 0;
}
