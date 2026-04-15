#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int dp[42];
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    string s; cin>>s;
    v.push_back(0);
    for(int i=0; i<s.length(); ++i){
        v.push_back(s[i]-48);
    }
    dp[1] = 1;
    if(v[2] == 0) dp[2] = 1;
    else if(v[1]<3) dp[2] = 2;
    else{
        if(v[1] == 3 && v[2] <= 4) dp[2] = 2;
        else dp[2] = 1;
    }
    for(int i=3; i<=s.length(); ++i){
        if(v[i] == 0){
            dp[i] = dp[i-2];
            continue;
        }
        if(v[i-1] == 0){
            dp[i] = dp[i-1];
            continue;
        }
        if(v[i-1]<3) dp[i] = dp[i-1] + dp[i-2];
        else if(v[i-1] == 3){
            if(v[i]<= 4) dp[i] = dp[i-1] + dp[i-2];
            else dp[i] = dp[i-1];
        }
        else dp[i] = dp[i-1];
    }
    cout<<dp[s.length()];
    return 0;
} 
