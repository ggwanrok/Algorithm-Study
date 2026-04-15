#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector <int> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    int a=1, b=1;
    int cnt = 0;
    for(int b=1; b<500; ++b){
        for(int a=1; a<500; ++a){
        if(a*a < b*b +n) continue;
        if(a*a == b*b + n) cnt++;
        }
    }
    cout<<cnt;
}
