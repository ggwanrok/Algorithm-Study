#include <bits/stdc++.h>
using namespace std;
int arr[5001];
int N, M;
bool f(int x){
    int cnt=1;
    int Min=arr[0], Max=arr[0];
    int rangeMax=0;
    for(int i=1; i<N; ++i){
        if(max(Max,arr[i])-min(Min,arr[i])>x){
            rangeMax=max(rangeMax,Max-Min);
            cnt++;
            Max=arr[i];
            Min=arr[i];
        }
        else{
            Max=max(Max,arr[i]);
            Min=min(Min,arr[i]);
        }
    }
    rangeMax=max(rangeMax,Max-Min);
    if(rangeMax<=x && cnt<=M) return true;
    return false;
}
int main(){
    cin>>N>>M;
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    int lo=-1, hi=9999;
    while(lo<hi-1){
        int mid=(lo+hi)/2;
        if(!f(mid)){
            lo=mid;
        }
        else{
            hi=mid;
        }
    }
    cout << hi << '\n';
}
