#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
최대 합을 구해야 한다.
각 인덱스마다, 최고값을 기록해주면 됨.

*/

int n;
int dp[1001];
vector<int> input_number;

void input(){
    cin>>n;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        input_number.push_back(k);
    }
}
void func(){
    int res = dp[0];
    for(int i=0; i<input_number.size(); i++){
        dp[i] = input_number[i];
        for(int j=0; j<i; j++){
            if(input_number[j] < input_number[i] && dp[i] < dp[j] + input_number[i])
            dp[i] =dp[j] + input_number[i];
        }
        res = max(res, dp[i]);
    }
    cout<<res<<'\n';
}

int main(){
    input();
    func();
    return 0;
}