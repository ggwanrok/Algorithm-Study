#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v[21];
int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    v[1].push_back({1, 3});
    for(int i=2; i<=n; i++){
        //전 것을 순회 (3<->2)
        for(auto iter : v[i-1]){
            int fir = iter.first;
            int sec = iter.second;
            if(fir == 2) fir = 3;
            else if(fir == 3) fir = 2;
            if(sec == 2) sec = 3;
            else if(sec == 3) sec = 2;
            v[i].push_back({fir, sec});
        }
        v[i].push_back({1, 3});
        //전 것을 순회 (1<->2)
        for(auto iter : v[i-1]){
            int fir = iter.first;
            int sec = iter.second;
            if(fir == 2) fir = 1;
            else if(fir == 1) fir = 2;
            if(sec == 2) sec = 1;
            else if(sec == 1) sec = 2;
            v[i].push_back({fir, sec});
        }
    }
    
    cout<<v[n].size()<<'\n';
    for(auto iter : v[n]){
        int fir = iter.first;
        int sec = iter.second;
        cout<<fir<<' '<<sec<<'\n';
    }
    return 0;
}