#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> v;

bool compare(string a, string b){
    return a+b > b+a;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), compare);

    string res = "";
    for(const auto& str : v){
        res += str;
    }
    if(res[0] == '0'){
        cout<<0<<'\n';
    }
    else{
        cout<<res;
    }
    return 0;
}