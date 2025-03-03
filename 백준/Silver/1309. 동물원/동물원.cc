#include <bits/stdc++.h>

using namespace std;

/*
n번째 열에 둘 수 있는 경우.
ox, xo, xx 이렇게임.
이 때, i단계에서 
ox 를 두는 경우는 i-1 번째 단계에서 xx, xo를 둔 경우들에 해당됨.
이에 따라서 점화식을 구성하고 n단계까지 이어나간다면 풀이가 될 것.
*/

int main(){
    int n; cin>>n;
    int arr[3][100001];
    arr[0][0] = 1; // ox
    arr[1][0] = 1; // xo
    arr[2][0] = 1; // xx
    for(int i=1; i<n; i++){
        arr[0][i] = (arr[1][i-1] + arr[2][i-1]) % 9901;
        arr[1][i] = (arr[0][i-1] + arr[2][i-1]) % 9901;
        arr[2][i] = (arr[0][i-1] + arr[1][i-1] + arr[2][i-1]) % 9901;
    }
    int res = (arr[0][n-1] + arr[1][n-1] + arr[2][n-1]) % 9901;
    cout<<res<<'\n';
    return 0;
}