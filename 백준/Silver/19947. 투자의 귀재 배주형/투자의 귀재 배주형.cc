#include <bits/stdc++.h>

using namespace std;

int pl[10] = {0, 5, 0, 20, 0, 35};

int arr[11];

int main(){
    int h, y;
    cin>>h>>y;
    for(int i=0; i<=y; i++){
        arr[i] = h;
    }
    for(int i=1; i<=y; i++){
        for(int j=1; j<=5; j++){
            if(pl[j] == 0) continue;
            int idx = i-j;
            if(idx < 0) continue;
            arr[i] = max(arr[i], arr[idx] + arr[idx] * pl[j] / 100);
        }
    }
    cout<<arr[y]<<'\n';
    return 0;
}