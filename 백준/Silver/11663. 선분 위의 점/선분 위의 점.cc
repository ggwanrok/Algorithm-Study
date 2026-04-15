#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int comp(int a, int b){
    if(a>b){
        return a<b;
    }
    return a<b;
}

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);

    int n, m; cin>>n>>m;
    vector <int> p = {0, };
    for(int i=0;i<n;++i){
        int a; cin>>a;
        p.push_back(a);
    }
    sort(p.begin(), p.end(), comp);
    for(int i=0;i<m;++i){
        int q,w; cin>> q >> w;
       cout<< upper_bound(p.begin(), p.end(), w) - lower_bound(p.begin(), p.end(), q)<<" \n";
    }
    return 0;
}