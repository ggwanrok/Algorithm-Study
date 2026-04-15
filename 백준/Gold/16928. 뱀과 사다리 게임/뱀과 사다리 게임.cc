#include <bits/stdc++.h>

using namespace std;

int n, m;
int board[105];
vector<int> ladder[105];
vector<int> snake[105];
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
    //1번부터 진행. 사다리가 존재
    //업데이트가 가능한 경우 큐에 넣어준다.
    board[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int k = q.front();
        q.pop();
        
        for(int i=1; i<=6; i++){
            int x = k + i;
            if(x > 100) continue;

            if(ladder[x].size() > 0){
                for(int i=0; i<ladder[x].size(); i++){
                    if(board[k] < board[ladder[x][i]]){
                        q.push(ladder[x][i]);
                        board[ladder[x][i]] = board[k]+1;
                    }
                }
            }
            else if(snake[x].size() > 0){
                for(int i=0; i<snake[x].size(); i++){
                    if(board[k] < board[snake[x][i]]){
                        q.push(snake[x][i]);
                        board[snake[x][i]] = board[k]+1;
                    }
                }
            }
            else{
                if(board[k]+1 < board[k+i]){
                    q.push(k+i);
                   board[k+i] = board[k] + 1;
                }
            }
        }
    }
}

void output(){
    cout<<board[100]<<'\n';
}

void input(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        ladder[a].push_back(b);
    }
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        snake[a].push_back(b);
    }
    for(int i=1; i<=100; i++){
        board[i] = 300;
    }
}