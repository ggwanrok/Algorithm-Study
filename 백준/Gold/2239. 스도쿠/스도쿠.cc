#include <bits/stdc++.h>

using namespace std;

int sudoku[10][10];

void input();
void func();
void fill_board(int);
void output();

int check_row(int, int);
int check_col(int, int);
int check_area(int, int, int);

int main(void){
    input();
    func();
    return 0;
}

int check_row(int x, int target){
    for(int i=0; i<9; i++){
        if(sudoku[x][i] == target) return 0;
    }
    return 1;
}
int check_col(int x, int target){
    for(int i=0; i<9; i++){
        if(sudoku[i][x] == target) return 0;
    }
    return 1;
}
int check_area(int x, int y, int target){
    x = (x / 3) * 3;
    y = (y / 3) * 3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(sudoku[x+i][y+j] == target) return 0;
        }
    }
    return 1;
}

void fill_board(int x){
    if(x == 81){
        output();
        exit(0);
    }
    int row = x / 9;
    int col = x % 9;
    if(sudoku[row][col] == 0){
        // 해당 셀에 들어가도 되는 수 : 행, 열, 구역에 있지 않은 수.
        for(int i=1; i<=9; i++){
            if(check_area(row, col, i) && check_row(row, i) && check_col(col, i)){
                sudoku[row][col] = i;
                fill_board(x+1);
            }
        }
        sudoku[row][col] = 0;
        return;
    }
    fill_board(x+1);
}

void func(){
    fill_board(0);
}

void input(){
    for(int i=0; i<9; i++){
        string s;
        cin>>s;
        for(int j=0; j<9; j++){
            sudoku[i][j] = s[j]-'0';
        }
    }
}

void output(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<sudoku[i][j];
        }
        cout<<'\n';
    }
}

