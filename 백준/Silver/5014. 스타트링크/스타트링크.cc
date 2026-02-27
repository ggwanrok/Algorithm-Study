#include <bits/stdc++.h>

using namespace std;

/*
f : 구조물 높이
s : 현재 위치
g : 목표 위치
u : 위로 u만큼 올라가기
d : 아래로 d 만큼 내려가기

적어도 몇번 눌러야 하는가? -> 눌리는 최소한의 횟수 -> bfs로 최초 도달 찾기

stair에서 
-1 : 목적지
0  : 방문이력 없음
1  : 방문이력 있음
*/

int f, s, g, u, d;

vector<int> stair;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>f>>s>>g>>u>>d;
    stair.resize(f+1, 0);
    
    queue<pair<int, int>> search;
    stair[s] = 1;
    stair[g] = -1;
    search.push({s, 0});
    while(!search.empty()){
        int cur_stair = search.front().first;
        int cur_movement = search.front().second;
        search.pop();
        if(cur_stair == g){
            cout<<cur_movement<<'\n';
            return 0;
        }

        if(cur_stair + u <= f && stair[cur_stair+u] != 1){
            stair[cur_stair+u] = 1;
            search.push({cur_stair+u, cur_movement+1});
        }
        if(cur_stair - d >= 1 && stair[cur_stair - d] != 1){
            stair[cur_stair - d] = 1;
            search.push({cur_stair - d, cur_movement+1});
        }
    }
    cout<<"use the stairs\n";
    return 0;
}