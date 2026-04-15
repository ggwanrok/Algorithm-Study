#include <bits/stdc++.h>

using namespace std;

/*
출력에 대한 생각을 사람처럼 하는 것은 힘들다.
주어진 최대표본을 표현할 수 있는 2차원 배열에 
알맞는 형태의 *를 저장해주기.
*/

int n;
int n_s; //n의 실질적 크기.

int loop_cnt;

char arr[2188][2188];

void input();
void func();
void output();

void clean_arr();
void make_base();
void find_n_s();

int main(){
    input();
    func();
    output();
    return 0;
}



void func() {
    clean_arr();
    find_n_s();
    make_base();
    if (n_s == 1) return;

    for (int loop = 1; loop <= n_s; loop++) {
        int base_size = pow(3, loop - 1); // 현재 기저 크기
        int big_size = base_size * 3;    // 새로운 크기

        // 새로운 패턴 복사
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 1 && j == 1) continue; // 가운데 부분은 공백 유지
                for (int r = 0; r < base_size; r++) {
                    for (int c = 0; c < base_size; c++) {
                        arr[i * base_size + r][j * base_size + c] = arr[r][c];
                    }
                }
            }
        }
    }
}

void clean_arr(){
    for(int i=0; i<2188; i++){
        for(int j=0; j<2188; j++){
            arr[i][j] = ' ';
        }
    }
}

void make_base(){
    arr[0][0] = arr[0][1] = arr[0][2] = '*';
    arr[1][0] = arr[1][2] = '*';
    arr[1][1] = ' ';
    arr[2][0] = arr[2][1] = arr[2][2] = '*';
}

void find_n_s(){
    int k = n;
    while(k!=1){
        k /= 3;
        n_s++;
    }
}

void input(){
    cin>>n;
}

void output(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j];
        }
        cout<<'\n';
    }
}
