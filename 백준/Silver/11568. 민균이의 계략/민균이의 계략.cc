#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> lis;
int cnt_arr[1001];
vector<int> arr;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        arr.push_back(k);
    }
    for(int i=0; i<arr.size(); i++){
        auto iter = lower_bound(lis.begin(), lis.end(), arr[i]);
        if(iter == lis.end()){
            lis.push_back(arr[i]);
        }
        else{
            *iter = arr[i];
        }
    }
    cout<<lis.size()<<'\n';
    return 0;
}