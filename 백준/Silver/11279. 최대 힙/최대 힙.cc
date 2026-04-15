#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct cmp{
    bool operator()(int a, int b){
        return a<b;
    }
};
priority_queue<int, vector<int>, cmp> pq;
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;++i){
        int t; cin>>t;
        if(t==0){
            if(pq.empty() == 1){
                cout<<0<<'\n';
            }
            else{
            cout<<pq.top()<<'\n';
            pq.pop();
            }
        }
        else{
            pq.push(t);
        }
    }
    return 0;
}