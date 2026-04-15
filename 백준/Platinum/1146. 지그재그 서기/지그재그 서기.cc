#include <iostream>
#include <cstring>
#define mod 1000000
using namespace std;

int dp[101][101][2]; //남은 좌항, 남은 우항, 기울기.

int n;
int res;
void input();

/*
첫번째, 두번째 요소를 지정
기울기와 선택된 두 요소를 기점으로 , 남은 좌항의 갯수와 우항의 갯수를 파악한 뒤,
아몰라 왜 안풀리는거야 짜증나게
*/
void func();
int solve(int, int, int);


int main(){
    input();
    func();
}


int solve(int left, int right, int graph){
    if(left == 0 && right == 0) return 1;
    if(left < 0 || right < 0) return 0;
    if(dp[left][right][graph] != -1) return dp[left][right][graph];
    
    int res_solve = 0;
    /*
    left : 좌항에 남은 요소의 갯수
    right : 우항에 남은 요소의 갯수
    graph : 최근 두개의 선택으로 인한 기울기의 상태
    */
    if(graph > 0){  // 하향
        //좌항은 right-1개. 우항은 n-right-1개
        //우항중에서 한개를 선택하여 다음 녀석을 봐야함. (상향)
        for(int i=0; i<right; i++){
            res_solve = (res_solve + solve(left+i, right-i-1, 0) % mod) % mod;
        }
    }
    else{  // 상향
        //좌항은 right-2개, 우항은 n-right개
        //좌항중에서 한개를 선택하여 다음 녀석을 봐야함. (하향)
        for(int i=0; i<left; i++){
            res_solve = (res_solve + solve(left-i-1, right+i, 1) % mod) % mod;
        }
    }
    return dp[left][right][graph] = res_solve;
}

void func(){
    if(n == 1) {
        cout<<1<<'\n';
        return;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) continue;

            if(i < j){
                res = (res + solve(j - 2, n - j, 0)) % mod;    
            }
            else{
                res = (res + solve(j - 1, n - j - 1, 1)) % mod;
            }
        }
    }
    cout<<res<<'\n';
}

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    res = 0;
    cin>>n;
    memset(dp, -1, sizeof(dp));
}