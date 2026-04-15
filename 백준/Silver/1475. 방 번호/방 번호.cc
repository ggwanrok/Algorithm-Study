#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> v;
    string s; cin>>s;
    int cnt = 1;
    map <int, int> m;
    for(int i=0; i<9; ++i){
        if(i==6){
            m[i] = 2;
        }
        else{
            m[i] = 1;
        }
    }
    for(int i=0; i<s.length(); ++i){
        v.push_back(s[i]-48);
    }
    for(int i=0; i<v.size(); ++i){
        if(v[i] == 9) v[i] = 6;
        m[v[i]]--;
        if(m[v[i]] == -1){
            cnt++;
            for(int i=0; i<9; ++i){
                if(i==6){
                m[i] += 2;
                }
            else{
                m[i] += 1;
                }
            } 
            }
    }
    cout<<cnt;
    return 0;
}
