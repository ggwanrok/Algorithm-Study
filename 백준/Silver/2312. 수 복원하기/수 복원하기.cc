#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    vector<pair<int, int>> v;//소인수 , 갯수
    for(int i=0;i<t;++i){
        int n; cin>>n;
        for(int j=2;j*j<=n;++j){
            if(n%j == 0){
                int cnt=0;
                while(n%j == 0){
                    ++cnt;
                    n /= j;
                }
                v.push_back({j, cnt});
            }
        }
        if(n != 1) v.push_back({n, 1});
    }
    for(vector<pair<int, int>> :: iterator it = v.begin(); it != v.end(); ++it){
            cout<<it->first<<" "<<it->second<<'\n';
        }
    return 0;
}