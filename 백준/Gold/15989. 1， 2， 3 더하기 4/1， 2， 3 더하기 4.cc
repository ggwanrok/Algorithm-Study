#include <bits/stdc++.h>

using namespace std;

/*
k를 나타내는 경우=
k-3 을 나타내는 경우 뒤에 3
k-2 를 나타내는 경우 뒤에 2
k-1 을 나타내는 경우 뒤에 1
*/

int arr[4][10001];

int sum_num(int);
void fill_arr();

int main(){
    memset(arr, 0, sizeof(arr));
    arr[1][1] = 1;
    arr[2][2] = 1;
    arr[3][3] = 1;
    fill_arr();
    int tc;
    cin>>tc;
    while(tc--){
        int n; cin>>n;
        cout<<sum_num(n)<<'\n';
    }
    return 0;
}
void fill_arr(){
    for(int i=1; i<=10000; i++){
        //[i][j] 에서, i로 끝나서 합이 j가 됨.
        if(i+1 <= 10000) arr[1][i+1] += arr[1][i];
        if(i+2 <= 10000) arr[2][i+2] += arr[1][i] + arr[2][i];
        if(i+3 <= 10000) arr[3][i+3] += arr[1][i] + arr[2][i] + arr[3][i];
    }
}

int sum_num(int n){
    return arr[1][n] + arr[2][n] + arr[3][n];
}