#include <bits/stdc++.h>
#define mod 1000000
using namespace std;

/*
조사하는 인덱스 자리에서,
해당 자리까지 따졌을 때, 나오는 경우의 수를 저장하자.
바라보는 자리에선, 직전 녀석을 따지는 것 + 전전 녀석에서 두자리 차지하면서 따지는 것.
으로 구분지어 진행시키면 될 것 같다.
*/

int res = 0;
string s;
vector<int> v;

bool check_now(const string s, int idx){
    int num = s[idx] - '0';
    if(num >= 1 && num <= 26) return true;
    return false;
}

bool check_pre(const string s, int idx){
    if(idx < 1) return false;
    if(s[idx-1] < '1' || s[idx-1] > '2') return false;
    if(s[idx] < '0' || s[idx] > '9') return false;    
    int num = (s[idx-1] - '0') * 10 + (s[idx] - '0');
    if(num >= 1 && num <= 26) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>s;
    v.resize(s.length()+5, 0);
    for(int i=0; i<s.length(); i++){
        if(check_now(s, i)){
            if(i >= 1) v[i] += v[i-1];
            else v[i] += 1;
            v[i] %= mod;
        }
        if(check_pre(s, i)){
            if(i >= 2) v[i] += v[i-2];
            else v[i] += 1;
            v[i] %= mod;
        }
    }
    cout<<v[s.length()-1]<<'\n';
    return 0;
}