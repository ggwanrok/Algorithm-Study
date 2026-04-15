#include <iostream>

using namespace std;

int self_num[15000];

void check_self(int n){
    int val = n;
    int cur_n = n;
    while(cur_n>0){
        val += cur_n%10;
        cur_n /= 10;
    }
    if(self_num[val]==0){
        self_num[val] = 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for(int i=1; i<=10000; i++){
        check_self(i);
    }
    for(int i=1; i<=10000; i++){
        if(self_num[i] == 0) cout<<i<<'\n';
    }

    return 0;
}