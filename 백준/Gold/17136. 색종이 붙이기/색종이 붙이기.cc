#include <iostream>

using namespace std;

void input();
void findans(int, int, int);
bool canPaste(int, int, int);
void pasting(int, int, int, int);
void output();
int arr[11][11];
int paper[6] = {0, 5, 5, 5, 5, 5};
int ans = 101;

int main(void){
    input();
    findans(0, 0, 0);
    output();
    return 0;
}

void input(){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            int k;
            cin>>k;
            arr[i][j] = k;
        }
    }
}

void findans(int x, int y, int count){
    //count가 ans값 이상인 경우에는 어차피 ans보다 더 좋은 결과일 수 없음.
    if(count >= ans){
        return;
    }

    // 탑색이 종료된 경우.
    if(x == 10 && y == 9){ 
        ans = ans < count ? ans : count;
        return;
    }
    //하나의 행이 다 읽힌 경우.
    if(x >= 10){
        findans(0, y+1, count);
        return;
    }

    //이제 스티커를 붙일 수 있는지 검사.
    /*
    스티커를 붙일 수 있다면, 붙이느 경우로 재귀(백트래킹) 을 진행해주고,
    해당 진행이 끝나면 스티커를 떼낸 뒤, 안붙인 경우로 탐색을 이어가도록 한다.
    */
    if(arr[x][y] == 1){
        for(int i=5; i>=1; i--){
            //해당좌표를 기점으로 i 사이즈의 색종이를 붙일 수 있는가?
            if(paper[i] > 0 && canPaste(x, y, i)){
                paper[i]--;
                pasting(x, y, i, 0);
                findans(x+i, y, count+1);
                paper[i]++;
                pasting(x, y, i, 1);
            }
        }
    }
    else{
        findans(x+1, y, count);
    }

}
void pasting(int x, int y, int size, int active){
    for(int i = x; i<x+size; i++){
        for(int j=y; j<y+size; j++){
            arr[i][j] = active;
        }
    }
}

bool canPaste(int x, int y, int size){
    for(int i=x; i<x+size; i++){
        for(int j=y; j<y+size; j++){
            if(i<0||i>=10||j<0||j>=10){
                return false;
            }
            if(arr[i][j] != 1){
                return false;
            }
        }
    }
    return true;
}

void output(){
    if(ans == 101){
        ans = -1;
    }
    cout<<ans<<'\n';
}