#include <bits/stdc++.h>

using namespace std;

vector<int> to_push;
int to_push_size;
int dp[5][5][100001];
int res;

void input();
void func();
void output();
int check(int , int);
int dp_func(int, int, int);

int main(){
    input();
    func();
    output();
    return 0;
}

void func(){
    //(0, 0)으로 부터 해서 left로 갔을 때, right로 갔을 때의 최솟값이 해당 자리에서의 도출값이 될듯.
    res = dp_func(0, 0, 0);
}

int dp_func(int a, int b, int target){
    /*
    완료될 때까지 나올 수 있는 모든 경우의 끝에서부터 차근차근 생성되는 최소값들을 리턴하여 최종 결과를 추린다.
    dp배열을 통한 메모이제이션 기법을 이용하여 시간소모를 줄일 수 있다.
    */
    if(target == to_push_size) return 0;
    //이미 해당자리 연산이 종료되었다면 
    if(dp[a][b][target] != -1) return dp[a][b][target];

    int next = to_push[target];
    int left = dp_func(next, b, target+1) + check(a, next);
    int right = dp_func(a, next, target+1) + check(b, next);

    return dp[a][b][target] = dp[b][a][target] = min(left, right);
}

int check(int before_a, int after_a){
    if(before_a == 0){
        return 2;
    }
    else if(before_a == after_a){
        return 1;
    }
    else if(before_a%2 == after_a%2){
        return 4;
    }
    else{
        return 3;
    }
}

void output(){
    cout<<res<<'\n';
}

void input(){
    while(1){
        int k; cin>>k;
        if(k == 0) break;
        to_push.push_back(k);
    }
    to_push_size = to_push.size();
    memset(dp, -1, sizeof(dp));
}