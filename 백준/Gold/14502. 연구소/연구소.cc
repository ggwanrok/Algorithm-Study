#include <bits/stdc++.h>

using namespace std;

int n, m; //크기 변수
int arr[9][9];//구역 상태표
int res = 0;
vector<pair<int, int>> two_pair; //2들의 위치가 기록됨. bfs 탐색 시작점
vector<pair<int, int>> zero_pair; //0들의 위치가 기록됨. 조합을 통해서 3개씩 1로 변경할 것.

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int temp[9][9]; // 0을 1로 3개를 변환한 arr의 카피변형본.

void input();
void func(); //3개씩 0을 1로 변경한 뒤, bfs를 호출하여 해당 표에서의 0갯수를 도출할 것.
void output();

int bfs(); //2들을 시작으로 bfs를 진행. 끝난 뒤, 해당 표에서의 0의 갯수를 측정하여 리턴.

int main(){
    input();
    func();
    output();
    return 0;
}

void func(){
    vector<int> comb(zero_pair.size(), 0);
    fill(comb.end()-3, comb.end(), 1);

    do{
        memcpy(temp, arr, sizeof(arr));

        for(int i=0; i<comb.size(); i++){
            if(comb[i] == 1){
                int x = zero_pair[i].first;
                int y = zero_pair[i].second;
                temp[x][y] = 1;
            }
        }

        res = max(res, bfs());
    } while(next_permutation(comb.begin(), comb.end()));
}



int bfs(){
    queue<pair<int, int>> q;
    for(auto p : two_pair){
        q.push(p);
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
            if(temp[xx][yy] == 0){
                temp[xx][yy] = 2;
                q.push({xx, yy});
            }
        }
    }

    int cnt = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(temp[i][j] == 0) cnt++;
        }
    }

    return cnt;
}

void input(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int k; cin>>k;
            arr[i][j] = k;
            if(k == 0){
                zero_pair.push_back({i, j});
            }
            if(k == 2){
                two_pair.push_back({i, j});
            }
        }
    }
}

void output(){
    cout<<res<<'\n';
}