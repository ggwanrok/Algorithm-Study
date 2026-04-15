#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL);
    int h, m;
    cin>>h>>m;
    int m_c = (m+15)%60;
    int h_c = (m+15)/60;
    if(!h_c) h--;
    cout<<(h+24)%24<<' '<<m_c<<'\n';
    return 0;
}