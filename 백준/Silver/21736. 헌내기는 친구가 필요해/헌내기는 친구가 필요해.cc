#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int arr[601][601];
int is_visit[601][601];
int res = 0;
pair<int, int> per;


int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c; cin>>c;
            if(c == 'I') {
                per = {i, j};
                arr[i][j] = 0;
            }
            else if(c=='O'){
                arr[i][j] = 0;
            }
            else if(c=='P'){
                arr[i][j] = 1;
            }
            else if(c=='X'){
                arr[i][j] = -1;
            }
        }
    }

    queue<pair<int, int>> q;
    is_visit[per.first][per.second] = 1;
    q.push(per);

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
                int xx = x + dx[i];
                int yy = y + dy[i];
                if(xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
                if(is_visit[xx][yy] == 1) continue;
                if(arr[xx][yy] == -1){
                    is_visit[xx][yy] = 1;
                    continue;
                }
                q.push({xx, yy});
                is_visit[xx][yy] = 1;
                if(arr[xx][yy] == 1) res++;
        }
    }

    if(res) cout<<res<<'\n';
    else cout<<"TT"<<'\n';

    return 0;
}