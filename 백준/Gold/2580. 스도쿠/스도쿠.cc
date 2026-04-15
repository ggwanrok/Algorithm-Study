#include <iostream>

using namespace std;

//각 기준을 기점으로, 1~9 까지의 숫자 중 무엇이 들었는지를 체크함.
int about_row[9][10]; 
int about_cal[9][10];
int about_area[9][10];

int game_board[9][9]; //스도쿠 판

void input();
bool game(int);
void output();

int get_area(int i, int j){
    return (i/3)*3 + j/3;
}

int main(void){
    input();
    game(0);
    output();
    return 0;
}

void input(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            int k;
            cin>>k;
            game_board[i][j] = k;
            about_row[i][k] = 1;
            about_cal[j][k] = 1;
            about_area[get_area(i, j)][k] = 1;
        }
    }
}

bool game(int num){
    if(num == 81){
        return true;
    }
    int row = num/9;
    int cal = num%9;
    if(game_board[row][cal] == 0){
        for(int i=1; i<=9; i++){
            if(about_row[row][i] == 0 && about_cal[cal][i] == 0 && about_area[get_area(row, cal)][i] == 0){
                about_row[row][i] = 1;
                about_cal[cal][i] = 1;
                about_area[get_area(row, cal)][i] = 1;
                game_board[row][cal] = i;
                if(game(num+1)) return true;
                about_row[row][i] = 0;
                about_cal[cal][i] = 0;
                about_area[get_area(row, cal)][i] = 0;
                game_board[row][cal] = 0;
            }
        }
    }
    else{
        return game(num+1);
    }
    return false;
}

void output(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<game_board[i][j]<<" ";
        }
        cout<<'\n';
    }
}