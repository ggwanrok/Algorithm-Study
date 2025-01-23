#include <bits/stdc++.h>

using namespace std;

/*
비행기가 입력 순서대로 도킹을 시도함.
단순한 수 연산으로 하는게 아니라, 뭔가 로직을 잡아야할듯.

*/

int g, p;
int res;

set<int> gates;

int main(){
    res = 0;
    cin>>g>>p;
    //남아있는 게이트를 의미함.
    for(int i=1; i<=g; i++){
        gates.insert(i);
    }
    //입력을 받아가면서 도킹을 시도함.
    for(int i=0; i<p; i++){
        int k; cin>>k;

        auto iter = gates.upper_bound(k);

        if(gates.size() == 0 || iter == gates.begin()) break;

        //도킹이 가능한 것이 있다.
        res++;
        gates.erase(--iter);
    } 
    cout<<res<<'\n';
    return 0;
}