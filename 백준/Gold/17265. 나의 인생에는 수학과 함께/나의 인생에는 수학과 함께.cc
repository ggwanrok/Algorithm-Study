/*
오른쪽, 아랫쪽으로만 이동할 수 있다
이는 받은 녀석은 윗놈 아니면 왼쪽에서만 받을 수 있다는 말이다.
ij가 정해지기 위해서는 
우선 i + j가 짝수일 때가 숫자인 상태라서 이걸 기본으로 비교를 진행한다.

음수와 양수가 곱해지는 경우는 고려하지 않아도 될 것 같다.
근거 : 사칙연산은 우선순위 없이 순서대로 주어진다.
기본적인 입력값은 모드 음이 아닌 정수로 주어진다.
그래서 곱셈으로 이어진다는 것이 어차피 음수끼리의 곱이 나올 수 없다.
*/

#include <bits/stdc++.h>

using namespace std;

int origin[10][10];
int n;

int calculate(int x, int y, int oper){
    if(oper == -1){
        return x+y;
    }
    else if(oper == -2){
        return x-y;
    }
    else {
        return x*y;
    }
}

bool is_correct(int a, int b){
    if(a >= 0 && a < n && b >= 0 && b < n) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char k; cin>>k;

            if(k >= '0' and k <= '5') origin[i][j] = k-'0';
            else{
                if(k == '+') origin[i][j] = -1;
                if(k == '-') origin[i][j] = -2;
                if(k == '*') origin[i][j] = -3;
            }
        }
    }

    int arr[10][10];
    memcpy(arr, origin, sizeof(origin));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if((i+j)%2 != 0) continue;
            int maxi = -100000000;
            int cnt = 0;
            if(is_correct(i-2, j)){
                maxi = max(maxi, calculate(arr[i-2][j], arr[i][j], arr[i-1][j]));
                cnt++;
            }
            if(is_correct(i-1, j-1)){
                maxi = max(maxi, calculate(arr[i-1][j-1], arr[i][j], arr[i-1][j]));
                maxi = max(maxi, calculate(arr[i-1][j-1], arr[i][j], arr[i][j-1]));
                cnt++;
            }
            if(is_correct(i, j-2)){
                maxi = max(maxi, calculate(arr[i][j-2], arr[i][j], arr[i][j-1]));
                cnt++;
            }
            if(cnt > 0) arr[i][j] = maxi;
        }
    }
    cout<<arr[n-1][n-1]<<' ';


    memcpy(arr, origin, sizeof(origin));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if((i+j)%2 != 0) continue;
            int mini = 100000000;
            int cnt = 0;
            if(is_correct(i-2, j)){
                mini = min(mini, calculate(arr[i-2][j], arr[i][j], arr[i-1][j]));
                cnt++;
            }
            if(is_correct(i-1, j-1)){
                mini = min(mini, calculate(arr[i-1][j-1], arr[i][j], arr[i-1][j]));
                mini = min(mini, calculate(arr[i-1][j-1], arr[i][j], arr[i][j-1]));
                cnt++;
            }
            if(is_correct(i, j-2)){
                mini = min(mini, calculate(arr[i][j-2], arr[i][j], arr[i][j-1]));
                cnt++;
            }
            if(cnt > 0) arr[i][j] = mini;
        }
    }
    cout<<arr[n-1][n-1]<<'\n';
    return 0;
}