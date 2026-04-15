#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int res;
vector<int> v;

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
    cout<<res<<'\n';
}

void func(){
    for(int i=0; i < v.size(); i++){
        res += v[i] * (v.size()-i);
    }
}

void input(){
    cin>>n;
    for(int i=0; i<n; i++){
        int c; cin>>c;
        v.push_back(c);
    }
    sort(v.begin(), v.end());
}