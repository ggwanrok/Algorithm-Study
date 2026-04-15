#include <bits/stdc++.h>

using namespace std;

int n;
int ground[30][30];
int visited[30][30];
vector<int> area_size;
int label;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void input();
void func();
void output();

int main(){
    input();
    func();
    output();
    return 0;
}

void output(){
    sort(area_size.begin(), area_size.end());
    cout<<area_size.size()<<'\n';
    for(int i=0; i<area_size.size(); i++){
        cout<<area_size[i]<<'\n';
    }
}

void func(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(ground[i][j] == 0 || visited[i][j] != 0) continue;
            int g_size = area_size.size();
            area_size.push_back(1);
            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = 1;
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int k=0; k<4; k++){
                    int xx = x + dx[k];
                    int yy = y + dy[k];
                    if(xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
                    if(ground[xx][yy] == 0 || visited[xx][yy] == 1) continue;
                    area_size[g_size]++;
                    visited[xx][yy] = 1;
                    q.push({xx, yy});
                }
            }
        }
    }
}

void input(){
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<n; j++){
            ground[i][j] = s[j] - '0';
        }
    }
}