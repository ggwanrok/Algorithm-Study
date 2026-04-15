#include <bits/stdc++.h>

using namespace std;

//간단하게 전것과 5단계 전 것과 붙어있어서 그 두 값을 더해주면 해당 단계의 값을 구할 수 있는듯

int tc;


long long arr[101];

int main(){
    cin>>tc;
    arr[1] = 1; arr[2] = 1; arr[3] = 1; arr[4] = 2; arr[5] = 2;
    for(int i=6; i<=100; i++){
        arr[i] = arr[i-1] + arr[i-5];
    }
    while(tc--){
        int t;
        cin>>t;
        cout<<arr[t]<<'\n';
    }
    return 0;
}