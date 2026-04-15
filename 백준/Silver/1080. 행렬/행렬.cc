#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[51][51];
int brr[51][51];
int to_same[51][51];

int res = 0;


void input();
void make_pre_matrix();
void trans_matrix(int, int);
void func();
void output();
//to_same 이 친구를 모두 1로 만들어주는게 목표다.

int main(void){
    input();
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<to_same[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    func();
    output();
    //     for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<to_same[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    return 0;
}

void func(){
    int row = 0;
    int col = 0;
    while(1){
        if(col+3 < m){
            trans_matrix(row, col);
            col++;
        }
        else if(col+3 == m && row+3 < n){
            trans_matrix(row, col);
            col = 0;
            row++;
        }
        else if(col+3 == m && row + 3 == n){
            trans_matrix(row, col);
            break;
        }
        else{
            break;
        }
    }
}

void make_pre_matrix(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == brr[i][j]){
                to_same[i][j] = 1;
            }
            else{
                to_same[i][j] = 0;
            }
        }
    }
}

void trans_matrix(int x, int y){
    if(to_same[x][y] != 0) return;
    res++;
    for(int i=x; i<x+3; i++){
        for(int j=y; j<y+3; j++){
            to_same[i][j] = (to_same[i][j] + 1) %2;
        }
    }
}

void input(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<m; j++){
            arr[i][j] = s[j]-'0';
        }
    }
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<m; j++){
            brr[i][j] = s[j]-'0';
        }
    }
    make_pre_matrix();
}

void output(){
    int flag = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(to_same[i][j] == 0){
                flag = 1;
            }
        }
    }
    if(flag == 1){
        cout<<-1<<'\n';
    }
    else{
        cout<<res<<'\n';
    }
}