#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int real_res;
int fake_res;

int n;

int real_map[101][101];
int fake_map[101][101];

int real_check[101][101];
int fake_check[101][101];

void input();
void func();
void output();
void bfs_1(int, int);
void bfs_2(int, int);

int main(void){
    input();
    func();
    output();
    return 0;
}

void bfs_1(int i, int j){
    //해당 기점의 포인트를 시작으로 bfs를 돌려서 탐색하지 않은 같은 녀석이 없을 때까지 수행.
    int base = real_map[i][j];
    queue<pair<int, int>> q;
    q.push({i, j});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
            //base와 동치비교 후, 방문체크를 해준다.
            if(real_map[xx][yy] != base) continue;
            if(real_check[xx][yy] != 0) continue;
            q.push({xx, yy});
            real_check[xx][yy] = 1;
        }
    }
}

void bfs_2(int i, int j){
    //해당 기점의 포인트를 시작으로 bfs를 돌려서 탐색하지 않은 같은 녀석이 없을 때까지 수행.
    int base = fake_map[i][j];
    queue<pair<int, int>> q;
    q.push({i, j});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
            //base와 동치비교 후, 방문체크를 해준다.
            if(fake_map[xx][yy] != base) continue;
            if(fake_check[xx][yy] != 0) continue;
            q.push({xx, yy});
            fake_check[xx][yy] = 1;
        }
    }
}

void func(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(real_check[i][j] == 0){
                real_res++;
                real_check[i][j] = 1;
                bfs_1(i, j);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(fake_check[i][j] == 0){
                fake_res++;
                fake_check[i][j] = 1;
                bfs_2(i, j);
            }
        }
    }

}

void input(){
    cin>>n;
    for(int i=0; i<n; i++){
        string input_str;
        cin>>input_str;
        for(int j=0; j<n; j++){
            real_map[i][j] = input_str[j];
            if(input_str[j] == 'B'){
                fake_map[i][j] = 0;
            }
            else{
                fake_map[i][j] = 1;
            }
        }
    }
}

void output(){
    cout<<real_res<<' '<<fake_res<<'\n';
}