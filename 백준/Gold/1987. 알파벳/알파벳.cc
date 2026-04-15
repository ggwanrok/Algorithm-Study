#include <bits/stdc++.h>

using namespace std;

int r, c;
int res = 0;
char area[21][21];
int alpha_check[30];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

/*
(0,0)부터 시작해서, 얼마나 더 이동할 수 있느냐 를 따지는 문제.
사용한 알파벳들을 기준으로 더 갈 수 있다 -> 가본다.
갈 수 없다 -> 현시점을 최대치와 비교해본다.
이걸 가지고 너비우선탐색을 진행하면 될듯?
-> 근데, 너비우선으로 해버리면 사용한 알파벳의 중복검사에 차질이 생길듯. 이건 깊이우선이 맞다
*/
void input();
void func();
void dfs(int, int, int);

void output();

int main(){
    input();
    func();
    output();
    return 0;
}

void dfs(int x, int y, int value){
    res = max(res, value);
    for(int i=0; i<4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx < 0 || yy < 0 || xx >= r || yy >= c) continue;
            if(alpha_check[area[xx][yy]-'A'] != 0) continue;
            alpha_check[area[xx][yy]-'A'] = 1;
            dfs(xx, yy, value+1);
            alpha_check[area[xx][yy]-'A'] = 0;
        }
}

void func(){
    alpha_check[area[0][0]-'A'] = 1;
    dfs(0, 0, 1);
}


void input(){
    cin>>r>>c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            char k;
            cin>>k;
            area[i][j] = k;
        }
    }
}

void output(){
    cout<<res<<'\n';
}