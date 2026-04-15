

#include <iostream>

using namespace std;

int n;
int res;
bool check_1[300], check_2[300], check_3[300];

void sol(int y){
    if(y >= n){
        res++;
        return;
    }
    for(int x=0; x<n; x++){
        if(check_1[x] || check_2[n+x-y] || check_3[x+y]) continue;
        check_1[x] = true;
        check_2[n+x-y] = true;
        check_3[x+y] = true;
        sol(y+1);
        check_1[x] = false;
        check_2[n+x-y] = false;
        check_3[x+y] = false;

    }
}

int main(void){
    cin>>n;
    sol(0);
    cout<<res<<'\n';
    return 0;
}