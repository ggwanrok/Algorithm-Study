#include <iostream>

using namespace std;
const int MAX_N = 1000;
bool isErased[MAX_N+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    isErased[0] = true;
    isErased[1] = true;
    for(int p=2; p*p <=1000; ++p){
        if(isErased[p]) continue;
        for(int j=p*p; j<=1000; j+=p){
            isErased[j]=true;
        }
    }
    int cnt = 0;
    while(N--){
        int K; cin >> K;
        if(!isErased[K]) cnt++;
    }
    cout<<cnt<<'\n';
}