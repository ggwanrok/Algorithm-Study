#include <bits/stdc++.h>

using namespace std;

string dp[251];

string add_dp(const string & s1, const string & s2){
    string res_str = "";
    int sum = 0;
    int i = s1.length()-1;
    int j = s2.length()-1;

    while(i >= 0 || j >= 0 || sum > 0){
        if(i >= 0) sum += s1[i--] -'0';
        if(j >= 0) sum += s2[j--] -'0';
        res_str += (sum %10) + '0';
        sum /= 10;
    }

    reverse(res_str.begin(), res_str.end());
    return res_str;
}

int main(){
    int n;;
    dp[0] = "1";
    dp[1] = "1";
    for(int i=2; i<=250; i++){
        dp[i] = add_dp(dp[i-2], dp[i-2]);
        dp[i] = add_dp(dp[i], dp[i-1]);
    }
    while(cin>>n){
        cout<<dp[n]<<'\n';
    }
    return 0;
}