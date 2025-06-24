// start : 02:10
#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100001];
int sum[100001][2];
int res;

int main(){
    cin>>n;
    res = -1000000000;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    //각 누적합 인덱스는 해당 요소가 사용될 때의 최댓값을 도출해야 함.
    //이전 녀석이 음수가 아니라면 더해주면 되는 것.
    //매 시점 제거한 상태에서, 제거 안한 상태에서를 고려하면 됨.
    sum[0][0] = arr[0];
    sum[0][1] = arr[0];
    for(int i=1; i<n; i++){
        //제거 코인을 사용하지 않은 상태에서의 최대요소
        sum[i][0] = (sum[i-1][0] > 0) ? sum[i-1][0] + arr[i] : arr[i];
        //제거 코인을 지금 사용하거나, 이전에 사용했을 때의 최대요소
        sum[i][1] = max(sum[i-1][0], sum[i-1][1] + arr[i]);
    }
    for(int i=0; i<n; i++){
        res = max(res, max(sum[i][0], sum[i][1]));
    }
    cout<<res<<'\n';
    return 0;
}
//end : 02:29