#include <iostream>

using namespace std;

//부분합 문제인 것 같음.

int n, m;
int arr[301][301];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int k; cin>>k;
            arr[i][j] = k+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }
    }
    int tc;
    cin>>tc;
    while(tc--){
        int x, y, xx, yy;
        cin>>x>>y>>xx>>yy;
        cout<<arr[xx][yy]-arr[xx][y-1]-arr[x-1][yy]+arr[x-1][y-1]<<'\n';
    }

    return 0;
}