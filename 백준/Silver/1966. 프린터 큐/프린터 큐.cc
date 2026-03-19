#include <bits/stdc++.h>

using namespace std;

/*
문서의 총 갯수와 내가 뽑고자 하는 녀석의 초기 위치를 제공해준다.
이후 각 문서를 0번째부터 n-1번째까지 우선도를 알려준다.

그냥 우선순위 큐 하나만 두기에는 무리가 있네.
우선순위 큐 하나만 둔다면, 같은 우선도 여러개가 있을 때, 11911과 같을 때,
첫 1을 뽑고자 했다면 세번째 1을 뽑을 때 뽑히지만,
우선순위 큐만 사용한다면 첫 1로 뽑히게 될 것이다.

입력된 순서대로 각 인덱스를 큐에 넣어둔다.
큐의 front가 우선순위가 가장 높은 녀석이 아니라면 pop, push 해준다.
*/

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n, m;
        cin>>n>>m;
        int cnt=0;
        queue<int> real_q;
        priority_queue<int> pri_q;
        map<int, int> pri_m; //idx, pri
        for(int i=0; i<n; i++){
            int pri; cin>>pri;
            real_q.push(i);
            pri_q.push(pri);
            pri_m.insert({i, pri});
        }
        while(!real_q.empty()){
            /*
            큐의 프론트의 우선도가 최상단이라면 뺸다. 동시에 우선순위 큐에서도 해당 녀석을 제거한다.
            아니라면, 다시 큐에 넣는다. 
            */
            if(pri_m[real_q.front()] == pri_q.top()){
                cnt++;
                if(real_q.front() == m){
                    break;
                }
                real_q.pop();
                pri_q.pop();
            }
            else{
                int tmp = real_q.front();
                real_q.pop();
                real_q.push(tmp);
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}