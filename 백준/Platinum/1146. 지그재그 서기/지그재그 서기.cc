#include <iostream>
#include <cstring>
#define mod 1000000
using namespace std;

int dp[101][101][2]; // 남은 좌항, 남은 우항, 기울기
int n, res;

void input();
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

    if(graph > 0){  // 하향
        if(right > 0){ // right > 0일 때만 루프 실행
            for(int i=0; i<right; i++){
                res_solve = (res_solve + solve(left+i, right-i-1, 0) % mod) % mod;
            }
        }
    }
    else{  // 상향
        if(left > 0){ // left > 0일 때만 루프 실행
            for(int i=0; i<left; i++){
                res_solve = (res_solve + solve(left-i-1, right+i, 1) % mod) % mod;
            }
        }
    }
    return dp[left][right][graph] = res_solve;
}

void func(){
    if(n == 1) {
        cout << 1 << '\n';
        return;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j) continue;

            if(i < j){
                if(j - 2 >= 0) res = (res + solve(j - 2, n - j, 0)) % mod;    
            }
            else{
                if(j - 1 >= 0 && n - j - 1 >= 0) res = (res + solve(j - 1, n - j - 1, 1)) % mod;
            }
        }
    }
    cout << res << '\n';
}

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    res = 0;
    cin >> n;
    memset(dp, -1, sizeof(dp));
}
