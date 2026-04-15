#include <bits/stdc++.h>

using namespace std;
//이름과 작업이 하나씩 끊어져서 제공됨.

map<string, int> m;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        m.clear();
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            string a, b;
            cin>>a>>b;
            if(m.find(b) == m.end()){
                m.insert({b, 1});
            }
            else{
                m[b] = m[b] + 1;
            }
        }
        int res = 1;
        if(m.size()){
            for(const auto &it : m){
                res *= (it.second + 1);
            }
        }
        cout<<res-1<<'\n';
    }
    return 0;
}