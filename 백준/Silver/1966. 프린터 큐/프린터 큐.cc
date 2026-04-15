#include <iostream>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    for(int j=0; j<t; ++j){
        int n; int ind; cin>>n>>ind;
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        int res =1;
        for(int i=0; i<n; ++i){
            int im; cin>>im;
            q.push(make_pair(i, im));
            pq.push(im);
        }
        while(1){
            if(q.front().second == pq.top() && q.front().first == ind){
                cout<<res<<'\n';
                res = 1;
                break;
            }
            else if(q.front().second == pq.top()){
                pq.pop();
                q.pop();
                res++;
            }
            else {
                q.push(q.front());
                q.pop();
            }
        }
    }
    return 0;
}