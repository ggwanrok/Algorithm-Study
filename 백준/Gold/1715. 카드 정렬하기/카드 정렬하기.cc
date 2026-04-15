/*
각 초기데이터를 리프노드로 본 뒤,
합산을 부모노드들이라고 치자
그리고 각 부모노드들의 합이 최소가 되는 상태를 만들어보면
다양한 그래프의 형태가 나올 수 있겠지만,
그런 형태라면 각 상황에 가장 작은 값들 2개를 뽑으면 될 것 같다.
우선순위큐를 사용해보자*/

#include <bits/stdc++.h>

using namespace std;
int res;
priority_queue<int, vector<int>, greater<>> pq;
int main(){
    int n; cin>>n;
    res = 0;
    for(int i=0; i<n; i++){
        int card;cin>>card;
        pq.push(card);
    }
    while(pq.size() >= 2){
        int fir = pq.top();
        pq.pop();
        int sec = pq.top();
        pq.pop();
        pq.push(fir+sec);
        res += fir+sec;
    }
    cout<<res<<'\n';
    return 0;
}