#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    string s; cin>>s;
    int q =1;
    int c=0;
    for(int i=0; i<s.length(); ++i){
        if(s[i] == '-') q= -1;
        else if(s[i] != ','){
            c = 10*c + s[i]-'0';
            }
        else if(s[i] == ','){
            v.push_back(c*q);
            q =1;
            c =0;
            }
        }
        v.push_back(c*q);
        for(int j=0; j<k; ++j){
            for(int i=1; i<v.size(); ++i){
                v[i-1] = v[i] - v[i-1];
            }
            v.pop_back();
        }
    for(int i=0; i<v.size(); ++i){
        if(i+1 != v.size()){
            cout<<v[i]<<",";
        }
        else cout<<v[i];
    }
    
    return 0;
}