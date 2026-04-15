#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> a;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    while(n--){
        int tmp;
        cin>>tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    cout<<a[k-1]<<'\n';

    return 0;
}