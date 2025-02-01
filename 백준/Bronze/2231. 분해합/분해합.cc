#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int res = 0;
    for(int i=0; i<=n; i++){
        int tmp = i;
        int var = i;
        while(var > 0){
            tmp += (var%10);
            var /= 10;
        }
        if(tmp == n) {
            res = i;
            break;
        }
    }
    cout<<res<<'\n';
    return 0;
}