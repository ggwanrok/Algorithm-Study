#include <bits/stdc++.h>

using namespace std;

struct robot{
    int x;
    int y;
    int state;
    robot(int x, int y, int state) : x(x), y(y), state(state) {}
}; 

int cnt;
int n, m;

int area[51][51]; // 0 : uncleaned , 1 : wall , 2 : cleaned

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int gaze = 0; //0 : up , 1 : right , 2 : dowm , 3 : left

bool is_area(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    return true;
}

void cleaning(int x, int y){
    if(area[x][y] == 0){
        area[x][y] = 2;
        cnt++;
    }
}
bool no_more_uncleaned_room(robot & ro){
    int x = ro.x;
    int y = ro.y;
    int state = ro.state;

    int flag = 0;
    for(int i=0; i<4; i++){
        if(is_area(x+dx[i], y+dy[i]) && area[x+dx[i]][y+dy[i]] == 0){
            //can cleaning
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        //can cleaning
        for(int i=1; i<=4; i++){
            int nxt = (state+i)%4;
            if(is_area(x + dx[nxt], y + dy[nxt]) && area[x + dx[nxt]][y + dy[nxt]] == 0){
                ro.x = x + dx[nxt];
                ro.y = y + dy[nxt];
                ro.state = nxt;
                break;
            }
        }
    }
    else{
        //cant cleaning
        if(is_area(x-dx[state], y-dy[state]) && area[x-dx[state]][y-dy[state]] != 1){
            ro.x = x-dx[state];
            ro.y = y-dy[state];
        }
        else{
            return false;
        }
    }
    return true;
}




int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    int a, b, c;
    cin>>a>>b>>c;
    if(c % 2 != 0) c = (c+2)%4;
    cnt = 0;

    robot r = robot(a, b, c);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>area[i][j];
        }
    }
    while(1){
        cleaning(r.x, r.y);
        if(!no_more_uncleaned_room(r)){
            break;
        }
    }
    cout<<cnt<<'\n';
    return 0;
}