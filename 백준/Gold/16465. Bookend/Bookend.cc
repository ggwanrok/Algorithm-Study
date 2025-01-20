#include <bits/stdc++.h>

using namespace std;

int n, m, l; //책의 갯수(필요없음) -> wei 로 대체. 책장의 너비. 북엔드의 너비.
int wei;
/*
북엔드 설치가 가능한가?
책은 다 담을 수 있는가?
그렇다면 북엔드를 몇개 사용할 것인가?
*/

void input();
void func();

int main(){
    input();
    func();
    return 0;
}

void func(){
    /*
    책의 총 너비. - wei
    책장의 너비. - m
    북엔드의 너비. - l
    */
    if(m > wei){
        if(wei >= l){
            cout<<1<<'\n';
        }
        else{
            if(m-wei >= l){
                cout<<1<<'\n';
            }
            else{
                cout<<-1<<'\n';
            }
        }

    }
    else if(m == wei){
        cout<<0<<'\n';
    }
    else{
        cout<<-1<<'\n';
    }
}

void input(){
    cin>>n>>m>>l;
    wei = 0;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        wei += k;
    }
}