#include <bits/stdc++.h>

using namespace std;


int area[51][51];
int is_visited[51][51];
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int num;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b;
    while(1){
        cin>>b>>a;
        num = 0;
        if(a==0 and b==0) break;
        //reset
        for(int i=0; i<a; i++){
            for(int j=0; j<b; j++){
                cin>>area[i][j];
                is_visited[i][j] = 0;
            }
        }

        for(int i=0; i<a; i++){
            for(int j=0; j<b; j++){
                if(area[i][j] != 0 and is_visited[i][j] == 0){
                    num++;
                    //DFS 실행
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    is_visited[i][j] = 1;
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(int l=0; l<8; l++){
                            int xx = x + dx[l];
                            int yy = y + dy[l];
                            if(xx < 0 || xx >= a || yy < 0 || yy >= b) continue;
                            if(is_visited[xx][yy] != 0) continue;
                            if(area[xx][yy] == 0) continue;
                            is_visited[xx][yy] = 1;
                            q.push({xx, yy});
                        }
                    }
                }
            }
        }
        cout<<num<<'\n';        

    }
    return 0;
}