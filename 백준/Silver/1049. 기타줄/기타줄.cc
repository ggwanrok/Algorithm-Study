#include <bits/stdc++.h>

using namespace std;

int n, m;
int li[101][2];
int res;
vector<int> v_6;
vector<int> v_1;

int main(){
    res = 0;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        
        v_6.push_back(a);
        v_1.push_back(b);
    }
    sort(v_1.begin(), v_1.end());
    sort(v_6.begin(), v_6.end());
    if(n >= 6){
        int value = min(v_1[0]*6 , v_6[0]);
        res += (value * (n / 6));
    }    
    res += min((n%6)*v_1[0], v_6[0]);
    cout<<res<<'\n';
    return 0;
}