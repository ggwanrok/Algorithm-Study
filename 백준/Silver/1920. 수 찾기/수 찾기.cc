#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int n; cin>>n;
    vector <int> v;
    for(int i=1;i<=n;++i){
        int a; cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int m; cin>>m;
    for(int i=0; i<m;++i){
        int b; cin>>b;
        cout << binary_search(v.begin(),v.end(), b) << '\n';
    }
    return 0;
}