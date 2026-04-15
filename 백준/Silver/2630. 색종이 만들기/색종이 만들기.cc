#include <iostream>

using namespace std;

/*
2의 거듭제곱형식으로 입력이 제한된다.
n을 시작으로 검사하는 영역을 줄여나가면 될듯?

검사 시작. 
1인가? 
ㄴ 맞다면 해당자리부터 검사 area만큼의 검사를 진행.
0인가? 도 똑같이 진행해줘야 할듯.

검사하는 거리단위 b 의 초깃값 = n. 꾸준히 더해가서
n^2 에 도달하면 b를 반갈하고 다시 진행.
*/

int res_1;
int res_0;
int n;
int arr[130][130];
int is_checked[130][130];

void input();
void func();
bool checking(int, int, int, int);//col, row, 1 or 0 여부
void set_check(int, int, int);
void output();

int main(){
    input();
    func();
    output();
    return 0;
}

bool checking(int x, int y, int b, int z_o){
    for(int i=x; i<x+b; i++){
        for(int j=y; j<y+b; j++){
            if(arr[i][j] != z_o){
                return false;
            }
        }
    }
    return true;
}

void set_check(int x, int y, int b){
    for(int i=x; i<x+b; i++){
        for(int j=y; j<y+b; j++){
            is_checked[i][j] = 1;
        }
    }
}

void func(){
    int b = n;
    while(b){
        //b가 더 쪼개져서 체크할 수 없어질 때까지 진행.
        int x = 0;
        int y = 0;
        while(x < n){
            if(!is_checked[x][y] && checking(x, y, b, arr[x][y])){
                set_check(x, y, b); //처리체크
                if(arr[x][y]) res_1++;
                else res_0++;
            }
            if(y + b >= n) {
                x += b;
                y = 0;
            }
            else y += b;
        }
        b /= 2;
    }
}

void input(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int c; cin>>c;
            arr[i][j] = c;
        }
    }
}

void output(){
    cout<<res_0<<'\n'<<res_1<<'\n';
}

