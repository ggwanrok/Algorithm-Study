#include <bits/stdc++.h>

using namespace std;

int n, m;
int area[1001][1001];
int move_to_end[1001][1001][2];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void input();
void func();
void output();

int main(void){
    input();
    func();
    output();
    return 0;
}

void func(){
    queue<pair<int, int>> q;
    q.push({0, 0});
    move_to_end[0][0][0] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
            /*
            move_to_end의 차원을 하나 늘려줘야 할듯.
            갱신이 일어날 때마다, 큐에 넣어주는 방식으로 한다.
            2번의 추가 작업들이 생기겠네.
            본인의 0에서 갈 수 있는 경우는 다음 녀석에 따라서 달라짐.
            본인의 1에서 갈 수 있는 경우는 다음녀석이 0이어야만 하다.
            */
            int flag = -1;
            if(area[xx][yy] == 0){
                //1부숨, 0부숨에 대한 처리 둘 다 가능.
                if(move_to_end[x][y][1] + 1 < move_to_end[xx][yy][1]){
                    move_to_end[xx][yy][1] = move_to_end[x][y][1]+1;
                    flag = 0;
                }
                if(move_to_end[x][y][0] + 1 < move_to_end[xx][yy][0]){
                    move_to_end[xx][yy][0] = move_to_end[x][y][0]+1;
                    flag = 0;
                }
            }
            if(area[xx][yy] == 1){
                //0부숨에 대한 처리만 가능.
                if(move_to_end[x][y][0] + 1 < move_to_end[xx][yy][1]){
                    move_to_end[xx][yy][1] = move_to_end[x][y][0]+1;
                    flag = 0;
                }
            }
            if(flag == 0){
                q.push({xx, yy});
            }
            
        }
    }
}

void input(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<m; j++){
            area[i][j] = s[j]-'0';
            move_to_end[i][j][0] = 10000000;
            move_to_end[i][j][1] = 10000000;
        }
    }
}
void output(){
    int k = min(move_to_end[n-1][m-1][0], move_to_end[n-1][m-1][1]);
    if(k == 10000000){
        cout<<-1<<'\n';
    }
    else{
        cout<<k<<'\n';
    }
}