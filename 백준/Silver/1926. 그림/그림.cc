#include <iostream>

using namespace std;

int totalGroup;

int maxSize;
int curSize;

int paper[501][501];
int dp[501][501];

int searching(int i, int j, int row, int col){
    int sum = 0;
    int var1 = 0;
    int var2 = 0;
    int var3 = 0;
    int var4 = 0;
    if(paper[i][j] == 0 || dp[i][j] == 1){
        return sum;
    }
    dp[i][j] = 1;
    sum++;
    if(i+1 <= row){
        var1 = searching(i+1, j, row, col);
    }
    if(i-1 >= 0){
        var3 = searching(i-1, j, row, col);
    }
    if(j+1 <= col){
        var2 = searching(i, j+1, row, col);
    }
    if(j-1 >= 0){
        var4 = searching(i, j-1, row, col);
    }

    sum = sum + var1 + var2 + var3 + var4;

    return sum;
}

int main(void){

    totalGroup = 0;
    maxSize = 0;

    int n, m;
    cin>>n>>m;

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            paper[i][j] = 0;
            dp[i][j] = 0;
            if(i==0 || j==0){
                dp[i][j] = 1;
            }
        }
    }
    // 여기까지 진행해서, 배열 초기화.

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int k;
            cin>>k;
            paper[i][j] = k;
        }
    }
    // 입력 받아서 필드 값 배정.


    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(paper[i][j] == 1 && dp[i][j] == 0){
                totalGroup++;
                int k = searching(i, j, n, m);
                maxSize = (k>maxSize)? k:maxSize;
            }
        }
    }

    cout<<totalGroup<<'\n'<<maxSize<<'\n';

    return 0;
}