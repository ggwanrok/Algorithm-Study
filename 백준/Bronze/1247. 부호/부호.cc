#include <bits/stdc++.h>
#define ll long long
using namespace std;

int loop;

int main(){
    loop = 3;
    while(loop--){
        ll res = 0;
        int is_flood = 0;
        int test; cin>>test;
        for(int i=0; i<test; i++){
            ll k; cin>>k;
            //결국 flood 기점으로 원형의 형태를 유지한다고 생각하면 될듯.
            if(res > 0 && k > 0 && k > LLONG_MAX - res){
                //overflow
                is_flood++;
            }
            if(res < 0 && k < 0 && k < LLONG_MIN - res){
                //underflow
                is_flood--;
            }

            res += k;
        }
        
        if(is_flood>0){
            cout<<'+'<<'\n';
        }
        else if(is_flood<0){
            cout<<'-'<<'\n';
        }
        else if(res == 0){
            cout<<'0'<<'\n';
        }
        else if(res > 0){
            cout<<'+'<<'\n';
        }
        else if(res < 0){
            cout<<'-'<<'\n';
        }
    }
    return 0;
}