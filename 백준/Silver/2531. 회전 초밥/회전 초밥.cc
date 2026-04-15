#include <iostream>
#include <vector>
using namespace std;
int arr[3001];
vector <int> v;
int isCoupon=1;
int cnt=0; // 종류
int N,d,k,c;
void add(int pos){
    arr[v[pos]]+=1;
    if(v[pos]==c) isCoupon=0;
    if(arr[v[pos]]==1) cnt+=1;
}
void sub(int pos){
    arr[v[pos]]-=1;
    if(v[pos]==c && arr[v[pos]]==0) isCoupon=1;
    if(arr[v[pos]]==0) cnt-=1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>d>>k>>c;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        v.push_back(a);
    }
    for(int i=0; i<N; ++i){
        v.push_back(v[i]);
    }
    int res=0;
    for(int i=0; i<k; ++i){
        add(i);
    }
    for(int s=0; s<N; ++s){
        res=max(res,cnt+isCoupon);
        add(s+k);
        sub(s);
    }
    cout << res << '\n';
}