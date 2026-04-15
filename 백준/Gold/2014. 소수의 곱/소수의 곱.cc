#include <iostream>
#include <queue>
#include <vector>
#define ll long long
using namespace std;

priority_queue<ll, vector<ll>, greater<ll>> pq;
vector<int> v;

int k, n;

int main(){
    cin>>k>>n;
    while(k--){
        int num; cin>>num;
        v.push_back(num);
        pq.push(num);
    }
    int cnt = 1;
    int prev = 0;
    while(1){

        while(prev == pq.top()){
            pq.pop();
        }

        if(n == cnt){
            cout<<pq.top()<<'\n';
            break;
        }
        
        ll var = pq.top();
        prev = pq.top();
        pq.pop();
        for(ll v_var : v){
            if(var*v_var >= INT32_MAX) continue;
            pq.push(var * v_var);
            if(var % v_var == 0) break;
        }
        cnt++;
    }
    return 0;
}