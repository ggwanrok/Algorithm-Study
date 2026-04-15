#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n;
vector<int> v;
vector<int> in_v;
map<int, int> m;
void input();
void func();
void output();

int main(){
    input();
    func();
    output();
    return 0;
}

void output(){
    for(int i=0; i<in_v.size(); i++){
        cout<<m[in_v[i]]<<' ';
    }
    cout<<'\n';
}

void func(){
    sort(v.begin(), v.end());
    auto it = unique(v.begin(), v.end());
    v.erase(it, v.end());
    for(int i=0; i<v.size(); i++){
        int first = v[i];
        int second = i;
        m.insert({first, second});
    }
}

void input(){
    cin>>n;
    for(int i=0; i<n; i++){
        int c; cin>>c;
        v.push_back(c);
        in_v.push_back(c);
    }
}