#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
set<string> S;
vector<string> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    for(int i=0; i<N; ++i){
        string str; cin >> str;
        S.insert(str);
    }
    for(int i=0; i<M; ++i){
        string str; cin >> str;
        if(S.find(str) != S.end()) v.push_back(str);
    }
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for(auto it:v){
        cout << it << '\n';
    }
}