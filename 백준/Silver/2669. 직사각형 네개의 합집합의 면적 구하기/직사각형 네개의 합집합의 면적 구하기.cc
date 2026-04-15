#include <bits/stdc++.h>

using namespace std;

int arr[101][101];

int main(){
    for(int loop=0; loop<4; loop++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        for(int i=a; i<c; i++){
            for(int j=b; j<d; j++){
                arr[i][j] = 1;
            }
        }
    }
    int res =0;
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            if(arr[i][j] > 0) res++;
        }
    }
    cout<<res<<'\n';
    return 0;
}