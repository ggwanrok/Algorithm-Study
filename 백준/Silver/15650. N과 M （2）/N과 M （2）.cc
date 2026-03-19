#include <bits/stdc++.h>

using namespace std;

/*
이전 요소를 고려하지 않는 dfs로 가면 될 것 같은디.
현재 코려하고 있는 유효숫자 범위를 탐색한다.

n의 숫자 범위 제한에서, m개의 숫자를 선택해서
중복없이 오름차순 정리는

현재 출력할 수 있는 완성된 문자열의 길이.
해당 대상이 보유한 값. (이것보다는 커야함)
원하는 길이 (n, m)
현재까지 고려된 문자열
*/

void find_mth(int i, int j, int n, int m, string str){
    if(i == m){
        cout<<str<<'\n';
        return;
    }
    for(int c=j+1; c<=n; c++){
        find_mth(i+1, c, n, m, str+to_string(c)+" ");
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n-m+1; i++){
        find_mth(1, i, n, m, to_string(i)+" ");
    }
    return 0;
}