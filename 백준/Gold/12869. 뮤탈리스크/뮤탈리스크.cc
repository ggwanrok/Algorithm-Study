#include <bits/stdc++.h>

using namespace std;

struct point{
    int x, y, z, cnt;
};

int n;
int x, y, z;
int is_visited[61][61][61];

int dpoint[6][3] = {
    {9, 3, 1}, {9, 1, 3},
    {3, 9, 1}, {3, 1, 9},
    {1, 9, 3}, {1, 3, 9}
};

/*
9, 3, 1 을 깎으며, 어떤 식으로 공격해야 하는가?
표본데이터가 크지 않기 때문에 우선순위 큐를 통해서 해결해보도록 하자. 매 순간 번거롭지만, 푸시팝을 해주면서
-> 이건 그리디 방식이다.
반례가 존재한다. 
-> dp로 풀이하자~
다중 인원에 대한 복합적인 dp 진행을 어떤식으로 해야할까..

*/

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    if(n>=1){
        cin>>x;
    }
    if(n>=2){
        cin>>y;
    }
    if(n>=3){
        cin>>z;
    }
    
    //각 좌표를 공간죄표계의 좌표로 사용하여, 6가지의 방법을 사용하여 (0, 0, 0) 으로 도달하는 최소한의 경우를 구하면 될 것 같다. 

    queue<point> q;
    q.push({x, y, z, 0});
    is_visited[x][y][z]=1;
    while(!q.empty()){
        auto cur = q.front();
        int xx = cur.x;
        int yy = cur.y;
        int zz = cur.z;
        int ccnt = cur.cnt;
        if(xx == 0 and yy == 0 and zz == 0){
            cout<<ccnt<<'\n';
            exit(0);
        }
        q.pop();
        for(int i=0; i<6; i++){
            int xxx = max(0, xx-dpoint[i][0]);
            int yyy = max(0, yy-dpoint[i][1]);
            int zzz = max(0, zz-dpoint[i][2]);
            if(is_visited[xxx][yyy][zzz] != 0) continue;
            is_visited[xxx][yyy][zzz] = 1;
            q.push({xxx, yyy, zzz, ccnt+1});
        }
    }
    return 0;
}