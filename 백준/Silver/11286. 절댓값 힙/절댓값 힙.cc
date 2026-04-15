#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;
struct cmp{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)) return a>b;
        return abs(a)>abs(b);
    }
};
priority_queue<int, vector<int>, cmp> pq;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    for(int i=0; i<n; ++i){
        int t; cin>>t;
        if(t!=0){
            pq.push(t);
        }
        else {
            if(pq.empty()){
                cout<<'0'<<'\n';
            }
            else{
            cout<<pq.top()<<'\n';
            pq.pop();
        }
        }

    }
}