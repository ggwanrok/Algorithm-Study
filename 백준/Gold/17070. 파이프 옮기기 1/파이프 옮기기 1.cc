#include <bits/stdc++.h>

using namespace std;

int n;
int pipe_map[17][17];
int dp_map[17][17];

void input();
void dp_func(int, int, int);
void output();

int main(void){
    input();
    dp_func(1, 2, 1);
    output();
    return 0;
}

void dp_func(int x, int y, int num){
    if(x == n && y == n) return;
    if(num == 1){
        //가로로 누워있을 떄.
        //우선 다음 칸으로 갈 수 있는지를 따진 뒤, 0이라는 것을 확인하고 넘기기.
        if(y+1 <= n){
            if(pipe_map[x][y+1] == 0){
                dp_map[x][y+1]++;
                dp_func(x, y+1, 1);
            }
            if(x+1 <= n){
                if(pipe_map[x][y+1] == 0 && pipe_map[x+1][y] == 0 && pipe_map[x+1][y+1] == 0){
                    dp_map[x+1][y+1]++;
                    dp_func(x+1, y+1, 3);
                }
            }
        }

    }
    if(num == 2){
        //세로
        if(x+1 <= n){
            if(pipe_map[x+1][y] == 0){
                dp_map[x+1][y]++;
                dp_func(x+1, y, 2);
            }
            if(y+1 <= n){
                if(pipe_map[x][y+1] == 0 && pipe_map[x+1][y] == 0 && pipe_map[x+1][y+1] == 0){
                    dp_map[x+1][y+1]++;
                    dp_func(x+1, y+1, 3);
                }
            }
        }
    }
    if(num == 3){
        //대각선
        if(y+1 <= n){
            if(pipe_map[x][y+1] == 0){
                dp_map[x][y+1]++;
                dp_func(x, y+1, 1);
            }
        }
        if(x+1 <= n){
            if(pipe_map[x+1][y] == 0){
                dp_map[x+1][y]++;
                dp_func(x+1, y, 2);
            }
        }
        if(y+1 <= n && x+1 <= n){
                if(pipe_map[x][y+1] == 0 && pipe_map[x+1][y] == 0 && pipe_map[x+1][y+1] == 0){
                    dp_map[x+1][y+1]++;
                    dp_func(x+1, y+1, 3);
                }
            }
    }
}

void input(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>pipe_map[i][j];
        }
    }
}

void output(){
    cout<<dp_map[n][n]<<'\n';
}