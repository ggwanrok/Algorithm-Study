#include <bits/stdc++.h>

using namespace std;

int main(){
    int x, y, w, h;
    cin>>x>>y>>w>>h;
    int res, res1, res2;
    res1 = min(x, w-x);
    res2 = min(y, h-y);
    res = min(res1, res2);
    cout<<res<<'\n';
    return 0;
}