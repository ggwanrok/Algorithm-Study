#include <iostream>
#include <vector>
using namespace std;
long long a[100001];
long long b[100001];
long long c[100001];
vector <int> ch;
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int n; cin>>n;
    long long res =10010000001;
    for(int i=1; i<=n; ++i){
        int k; cin>>k;
        a[i] = k;
    }
    for(int i=2; i<=n; ++i){
        int k; cin>>k;
        b[i] = b[i-1] + k;
    }
    for(int i=1; i<=n; ++i){
        a[i] = a[i] + b[i];
    }
    for(int i=2; i<=n; ++i){
        int k; cin>>k;
        c[i] = c[i-1] + k;
    }
    for(int i=1; i<=n; ++i){
        res = min(res, (a[i] + c[n] - c[i]));
    }
    for(int i=1; i<=n; ++i){
        if(res == (long long)(a[i] + c[n] - c[i])){
            ch.push_back(i);
        }
    }
    cout<<ch[0]<<" "<<res;
    return 0;
}