#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1000001];

vector<int> vec;
void set_vector(){
    int k = 1;
    while(k <= 1000000){
        vec.push_back(k);
        k = k + 4*vec.size() + 1;
    }
}

int target;
int res;
void input();
void func();


int main(){
    set_vector();
    input();
    func();
    return 0;
}

void func(){
    for(int iter : vec){
        for(int i=iter; i<=target; i++){
            
            dp[i] = min(dp[i], dp[i-iter] + 1);
        }
    }
    cout<<dp[target]<<'\n';
}

void input(){
    cin>>target;
    res = 0;
    for(int i=0; i<=target; i++){
        dp[i] = i;
    }
}