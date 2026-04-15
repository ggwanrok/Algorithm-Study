#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int l = 1; int r = 2;//좌포인터 l , 우포인터 r [l, r) 의 구조이다.
    int n; cin>>n;
    int sum =1; //l 이상 r 미만의 값들의 합.
    int cnt =0;
    while(r<=n+1){
        if(sum==n){
            cnt++;
            sum = sum -l++ + r++;
        }
        else if(sum<n){
            sum+=r++;
        }
        else{
            sum-=l++;
        }
    }
    cout<<cnt<<'\n';
    return 0;
}