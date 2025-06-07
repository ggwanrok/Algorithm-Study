#include <bits/stdc++.h>

using namespace std;

bool is_good(int k, int len){
    if(len <= 1) return true;
    int num;
    string s = "1";
    for(int i=0; i<len-1; i++){
        s += "0";
    }
    num = stoi(s);
    // cout<<'k'<<' '<<k<<' '<<num<<'\n';
    //공차 잡기.
    int d = (k/num) - (k%num)/(num/10);
    for(int i = num; i > 1; i /= 10){
        if(k/i - (k%i)/(i/10) != d) return false;
        k %= i;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int res = 0;
    int n; cin>>n;
    //1000이하의 입력값.
    //1부터 1000까지 모든 수에 대해서 등차수열인지 판단하는 로직 잡기.
    for(int i=1; i<=n; i++){
        if(i >= 1 && i < 10){
            if(is_good(i, 1)) res++;
        }
        if(i >= 10 && i < 100){
            if(is_good(i, 2)) res++;
        }
        if(i >= 100 && i < 1000){
            if(is_good(i, 3)) res++;
        }
        if(i >= 1000){
            if(is_good(i, 4)) res++;
        }
    }
    cout<<res<<'\n';
    return 0;
}