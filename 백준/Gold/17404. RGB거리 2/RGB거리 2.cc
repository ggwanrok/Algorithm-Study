#include <bits/stdc++.h>
#define MAX 10000000
using namespace std;

int res = MAX;
int n;
int ori_arr[1005][3];
int dp_arr[1005][3];

void input();
void func();
int dp(int start_color);
void output();

int main(void){
    input();
    func();
    output();
    return 0;
}

void func(){
    // 0, 1, 2 중 첫 번째 집의 색을 고정하여 각각의 최소 비용 계산
    for(int i = 0; i < 3; i++){
        res = min(res, dp(i));
    }
    
}

int dp(int start_color){
    for (int i = 0; i < 3; i++) {
        if (i == start_color) dp_arr[0][i] = ori_arr[0][i];
        else dp_arr[0][i] = MAX;
    }
    
    for(int i = 1; i < n; i++){
        dp_arr[i][0] = min(dp_arr[i-1][1], dp_arr[i-1][2]) + ori_arr[i][0];
        dp_arr[i][1] = min(dp_arr[i-1][0], dp_arr[i-1][2]) + ori_arr[i][1];
        dp_arr[i][2] = min(dp_arr[i-1][0], dp_arr[i-1][1]) + ori_arr[i][2];
    }

    int min_cost = MAX;
    for(int i = 0; i < 3; i++){
        if(i != start_color) {
            min_cost = min(min_cost, dp_arr[n-1][i]);
        }
    }
    return min_cost;
}

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> ori_arr[i][j];
        }
    }
}
void output(){
    cout << res << '\n';
}
