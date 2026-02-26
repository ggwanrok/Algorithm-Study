#include <bits/stdc++.h>

using namespace std;

int is_prime[10001];

int tc;

void do_pre_func();

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    do_pre_func();

    cin>>tc;
    while(tc--){
        int target; cin>>target;
        int left_prime, right_prime;
        for(int cur_left=target/2; cur_left>0; cur_left--){
            if(is_prime[cur_left] == 1 and is_prime[target-cur_left] == 1){
                left_prime = cur_left;
                right_prime = target-cur_left;
                break;
            }
        }
        cout<<left_prime<<' '<<right_prime<<'\n';
    }

    return 0;
}


void do_pre_func(){
    fill(is_prime, is_prime+10001, 1);
    is_prime[0] = is_prime[1] = 0;
    for(int i=2; i<=10000; i++){
        if(is_prime[i] == 1){
            //소수판정.
            if(i * i > 10000) continue;
            for(int j=i*i; j<=10000; j+=i){
                is_prime[j] = 0;
            }
        }
    }
}
