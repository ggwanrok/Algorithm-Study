#include <iostream>
using namespace std;
typedef long long int ll;
ll arr[10001];
ll N, M;

ll f(ll n){
    ll sum=0;
    for(int i=0; i<N; ++i){
        if(arr[i]>n) sum+=n;
        else sum +=arr[i];
    }
    return sum;
}

int main(){
    cin >> N;
    ll sum=0, max_=-1;
    for(int i=0; i<N; ++i){
        cin >> arr[i];
        sum+=arr[i];
        if(max_<arr[i]) max_=arr[i];
    }
    cin >> M;
    if(sum<=M) {
        cout << max_ << '\n';
        return 0;
    }
    ll lo=0, hi=1000000001;
    while(lo<hi-1){
        ll mid = (lo + hi)/2;
        if(f(mid)<=M) lo=mid;
        else hi=mid;
    }
    cout << lo << '\n';
}