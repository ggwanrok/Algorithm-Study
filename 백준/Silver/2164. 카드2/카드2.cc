#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int n; cin>>n;
    deque <int> d;
    for(int i=1;i<=n;++i){
        d.push_front(i);
    }
    while(1){
        if(d.size() !=1){
        d.pop_back();
        int t = d.back();
        d.pop_back();
        d.push_front(t);
        }
        else{
            cout<<d.back()<<'\n';
            break;
        }
        
    }
    return 0;
}