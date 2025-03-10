#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;
vector<int> lis;

void input(){
    cin>>n;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        arr.push_back(k);
    }
}

void func(){
    lis.push_back(arr[0]);
    for(int i=1; i<n; i++){
        auto iter = lower_bound(lis.begin(), lis.end(), arr[i]);
        if(iter == lis.end()){
            lis.push_back(arr[i]);
        }
        else{
            *iter = arr[i];
        }
    }
    cout<<lis.size()<<'\n';
}

int main(){
    input();
    func();
    return 0;
}