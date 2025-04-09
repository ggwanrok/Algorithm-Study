#include <bits/stdc++.h>
#define MAX 1000000009 
using namespace std;

int tc, n;
int arr[1000001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    for(int i=1; i<=1000000; i++){
        for(int c=1; c<=3; c++){
            if(i-c < 0) continue;
            arr[i] += arr[i-c];
            arr[i] %= MAX;
        }
    }
    cin>>tc;
    while(tc--){
        cin>>n;
        cout<<arr[n]<<'\n';
    }
    return 0;
}