#include <bits/stdc++.h>

using namespace std;

int n, m;
int res = 0;
int arr[501][501];

void input();
void func();
void output();
int do_all(int, int);

int main(){
    input();
    func();
    output();
    return 0;
}

int do_all(int x, int y){
    int cur_max = 0;

    // 일자형, 2가지
    if(y+3 < m) cur_max = max(cur_max, arr[x][y] + arr[x][y+1] + arr[x][y+2] + arr[x][y+3]);
    if(x+3 < n) cur_max = max(cur_max, arr[x][y] + arr[x+1][y] + arr[x+2][y] + arr[x+3][y]);

    // 정사각형, 1가지
    if(x+1 < n && y+1 < m) cur_max = max(cur_max, arr[x][y] + arr[x+1][y] + arr[x][y+1] + arr[x+1][y+1]);

    // L자형, 8가지
    if (x + 2 < n && y + 1 < m) cur_max = max(cur_max, arr[x][y] + arr[x + 1][y] + arr[x + 2][y] + arr[x + 2][y + 1]);
    if (x + 2 < n && y + 1 < m) cur_max = max(cur_max, arr[x][y] + arr[x][y + 1] + arr[x + 1][y + 1] + arr[x + 2][y + 1]);
    if (x + 1 < n && y + 2 < m) cur_max = max(cur_max, arr[x][y] + arr[x + 1][y] + arr[x + 1][y + 1] + arr[x + 1][y + 2]);
    if (x + 1 < n && y + 2 < m) cur_max = max(cur_max, arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x + 1][y + 2]);

    // 대칭 L자형
    if (x + 2 < n && y + 1 < m) cur_max = max(cur_max, arr[x][y + 1] + arr[x + 1][y + 1] + arr[x + 2][y + 1] + arr[x + 2][y]);
    if (x + 2 < n && y + 1 < m) cur_max = max(cur_max, arr[x][y] + arr[x + 1][y] + arr[x + 2][y] + arr[x][y + 1]);
    if (x + 1 < n && y + 2 < m) cur_max = max(cur_max, arr[x][y] + arr[x + 1][y] + arr[x][y + 1] + arr[x][y + 2]);
    if (x + 1 < n && y + 2 < m) cur_max = max(cur_max, arr[x + 1][y] + arr[x + 1][y + 1] + arr[x + 1][y + 2] + arr[x][y + 2]);

    // T자형, 4가지
    if (x + 1 < n && y + 2 < m) cur_max = max(cur_max, arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x + 1][y + 1]);
    if (x + 2 < n && y + 1 < m) cur_max = max(cur_max, arr[x][y] + arr[x + 1][y] + arr[x + 2][y] + arr[x + 1][y + 1]);
    if (x + 1 < n && y + 2 < m) cur_max = max(cur_max, arr[x + 1][y] + arr[x + 1][y + 1] + arr[x + 1][y + 2] + arr[x][y + 1]);
    if (x + 2 < n && y + 1 < m) cur_max = max(cur_max, arr[x][y + 1] + arr[x + 1][y + 1] + arr[x + 2][y + 1] + arr[x + 1][y]);

    // 번개형, 4가지
    if (x + 2 < n && y + 1 < m) cur_max = max(cur_max, arr[x][y] + arr[x + 1][y] + arr[x + 1][y + 1] + arr[x + 2][y + 1]);
    if (x + 2 < n && y + 1 < m) cur_max = max(cur_max, arr[x][y + 1] + arr[x + 1][y] + arr[x + 1][y + 1] + arr[x + 2][y]);
    if (x + 1 < n && y + 2 < m) cur_max = max(cur_max, arr[x][y] + arr[x][y + 1] + arr[x + 1][y + 1] + arr[x + 1][y + 2]);
    if (x + 1 < n && y + 2 < m) cur_max = max(cur_max, arr[x + 1][y] + arr[x + 1][y + 1] + arr[x][y + 1] + arr[x][y + 2]);

    return cur_max;
}

void func(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            res = max(res, do_all(i, j));
        }
    }
}

void input(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
}

void output(){
    cout<<res<<'\n';
}