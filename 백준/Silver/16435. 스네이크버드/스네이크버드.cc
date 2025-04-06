#include <bits/stdc++.h>

using namespace std;

int n, l;
vector<int> apple;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>l;
    while(n--){
        int k; cin>>k;
        apple.push_back(k);
    }
    sort(apple.begin(), apple.end());
    int idx = 0;
    while(idx < apple.size()){
        if(apple[idx] <= l){
            idx++;
            l++;
        }    
        else{
            break;
        }
    }
    cout<<l<<'\n';
    return 0;
}