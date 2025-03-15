#include <bits/stdc++.h>

using namespace std;

int n;

//cnt가 홀수이면 분자가 더 큰거부터, 아니면 분모가.

int main(){
    cin>>n;

    int cnt = 1;

    while(n > cnt){
        n -= cnt;
        cnt++;
    }

    int sum_value = cnt+1;
    int val_1 = 1;
    int val_2 = cnt;
    while(--n){
        val_1++;
        val_2--;
    }

    if(cnt%2 == 0){
        cout<<val_1<<'/'<<val_2<<'\n';
    }
    else{
        cout<<val_2<<'/'<<val_1<<'\n';
    }

    return 0;
}