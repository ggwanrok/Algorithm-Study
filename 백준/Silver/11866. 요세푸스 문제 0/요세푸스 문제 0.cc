#include <iostream>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin>>n>>k;
    queue <int> q;
    int cnt =1;
    cout<<"<";
    for(int i=1; i<=n; ++i){
        q.push(i);
    }
    while(!q.empty()){
        for(int i=0; i<k-1; ++i){
            q.push(q.front());
            q.pop();
        }
        cout<<q.front();
        if(cnt<n) cout<<", ";
        cnt++;
        q.pop();
    }
    cout<<">";
    return 0;
}
