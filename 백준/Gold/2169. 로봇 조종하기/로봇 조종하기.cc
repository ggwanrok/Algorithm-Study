#include <bits/stdc++.h>

using namespace std;

/*
한번 탐사한 지역은 다시 탐사하지 않도록 한다.
각 좌표에 대한 이동방향 상태에 대한 정립이 필요한 것 같다.
1. 위에서 내려온 경우 : 좌, 우, 하 의 이동 가능성을 가진다.
2. 좌에서 온 경우 : 우, 하의 이동가능성을 가진다.
3. 우에서 온 경우 : 좌, 하의 이동가능성을 가진다.

우선 첫 행을 쭉 보낸다고 생각해.
그리고 각 지점에서 아래로 내려.
내린 지점에서, 양 끝에서 해당 지점까지 올 수 있는 최대치를 판단해
그리고 아래로 내려.
이걸 반복해.

맨 마지막은 내려받아서 오른쪽으로만 보내.
*/

int n, m;
int res;
int area[1001][1001];
int dp[1001][1001][2]; //[row][col][di(오른쪽 방향 / 왼쪽 방향)]

void input();
void func();
void output();

int main(){
    input();
    func();
    output();
    return 0;
}

void func(){
    dp[0][0][0] = dp[0][0][1] = area[0][0];
    for(int i=1; i<m; i++){
        dp[0][i][0] = dp[0][i][1]= area[0][i] + dp[0][i-1][0];
    }
    //첫줄은 채웠음. 아래는 윗 정보에서 max값 + 해당 줄을 통해서 도달할 수 있는 최댓값을 정하면 될 것 같다.
    //예를 들면, 3열 녀석을 특정하기 위해선 i열 전행의 최대 정보와 해당 열에서 3열까지 도달하는 정보를 종합.
    //최종적으로 가장 높은 정보를 가지는 녀석을 정리.
    for(int i=1; i<n; i++){
        //i행에 대한 작업을 진행해줄거다.
        dp[i][0][0] = max(dp[i-1][0][0], dp[i-1][0][1]) + area[i][0];
        dp[i][m-1][1] = max(dp[i-1][m-1][0], dp[i-1][m-1][1]) + area[i][m-1];
        //j열에 대한 작업을 진행해줄거다.
        for(int j=1; j<m; j++){
            dp[i][j][0] = area[i][j] + max(max(dp[i-1][j][0], dp[i-1][j][1]), dp[i][j-1][0]);
        }
        for(int j=m-2; j>=0; j--){
            dp[i][j][1] = area[i][j] + max(max(dp[i-1][j][0], dp[i-1][j][1]), dp[i][j+1][1]);
        }
    }

    res = max(dp[n-1][m-1][0], dp[n-1][m-1][1]);
}

void output(){
    cout<<res<<'\n';
}

void input(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    res = -200000000;
    memset(area, 0, sizeof(area));
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>area[i][j];
        }
    }
}