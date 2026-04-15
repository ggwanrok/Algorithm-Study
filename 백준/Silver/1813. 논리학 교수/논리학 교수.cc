/*
a개가 참이라는 말이 a번 반복되는 가장 큰 a가 출력되는 답이다.
만약 모든 a가 0이라면 모순이기 때문에 -1이 출력된다.
끝까지 갔는데에도, 첫줄이 충족되지 않는다면, 그것은 만족하는 문구가 없는 것이기에 0을 출력한다
*/
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<int, int> m;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    int k; 
    int oc=0;
    int mx =0;
    for(int i=0; i<n; ++i){
        cin>>k;
        m[k]++;
        if(k==0) oc++;
    }
    if(n == oc || k>n){
        cout<<"-1";
        return 0;
    }
    for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it){
        if(it->first == it->second){
            mx = max(mx, it->second);
        }
    }
    if(mx == 0 && m[0] != 0){
        cout<<"-1";
        return 0;
    }
    cout<<mx;
    return 0;
}