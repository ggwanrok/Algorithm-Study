#include <iostream>

using namespace std;

int r, c, k;
int res=0;
char ground[6][6];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void input();
//T가 아니라면 현재의 진행 숫자와 함께 벡트래킹.
//도착지는 {0, c-1} 일 것.

void func();
void output();
void movement(int, int, int);

int main(void){
    input();
    func();
    output();
    return 0;
}

void movement(int x, int y, int t){
    if(x == 0 && y == c-1){
        if(t == k) res++;
        return;
    }
    ground[x][y] = 'T';
    for(int i=0; i<4; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx < 0 || yy < 0 || xx >= r || yy >= c) continue;
        if(ground[xx][yy] == 'T') continue;
        
        movement(xx, yy, t+1);
        
    }
    ground[x][y] = '.';
}

void func(){
    if(ground[r-1][0] == 'T') return;
    movement(r-1, 0, 1);
}

void output(){
    cout<<res<<'\n';
}

void input(){
    cin>>r>>c>>k;
    for(int i=0; i<r; i++){
        string s;
        cin>>s;
        for(int j=0; j<c; j++){
            ground[i][j] = s[j];
        }
    }
}