#include <bits/stdc++.h>

using namespace std;

int n;
priority_queue<int> small_pq;
priority_queue<int, vector<int>, greater<>> big_pq;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    while(n--){
        int k; cin>>k;
        small_pq.push(k);
        //우선 큰 녀석에 넣어준 뒤,
        //큰 녀석보에 너무 많이 담길 경우, 정리해줌.
        if(!big_pq.empty() && small_pq.top() > big_pq.top()){
            int s_top = small_pq.top(); small_pq.pop();
            int b_top = big_pq.top(); big_pq.pop();
            small_pq.push(b_top);
            big_pq.push(s_top);
        }

        if(small_pq.size() > big_pq.size()+1){
            big_pq.push(small_pq.top());
            small_pq.pop();
        }

        cout<<small_pq.top()<<'\n';
    }
}