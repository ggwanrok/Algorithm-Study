#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n;
    int res = 1;
    int inc = 1;
    int dec = 1;

    vector<int> v;

    for(int i=0; i<n; i++){
        int k; cin>>k;
        v.push_back(k);
    }
    for(int i=1; i<n; i++){
        //i-1과 비교하여 증감에 대한 작업을 진행.
        if(v[i-1] == v[i]){
            inc++;
            dec++;
        }
        else if(v[i-1] < v[i]){
            inc++;
            dec = 1;
        }
        else{
            inc = 1;
            dec++;
        }
        int maxi = max(inc, dec);
        res = max(res, maxi);
    }
    cout<<res<<'\n';
    return 0;
}