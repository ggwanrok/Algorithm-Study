#include <bits/stdc++.h>

using namespace std;

/*
전체 구조가 정사각형 구조를 가진다.
행열 정보를 통해서 행 열정보가 필요하다.
n-1 구조로 잡고 해서
*/

int getting(int n, int i, int j){
    if(n == 2){
        return i*2 + j;
    }
    int sum_value = 0;
    int devide_value = n/2;
    if(i >= devide_value){
        sum_value += devide_value * devide_value * 2;
    }
    if(j >= devide_value){
        sum_value += devide_value * devide_value;
    }
    int nxt_i = i/devide_value;
    int nxt_j = j/devide_value;
    return sum_value + getting(n/2, i%devide_value, j%devide_value);
}

int main(){
    int n, r, c;
    cin>>n>>r>>c;
    int line_cnt = pow(2, n);

    //재귀로 타고 들어가야 할 것 같은데.
    /*
    현재 고려하는 위치에 대해서 cnt가 2가 되기 전까지 타고 내려가서
    */
    cout<<getting(line_cnt, r, c)<<'\n';
    return 0;
}