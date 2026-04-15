#include <bits/stdc++.h>

using namespace std;

int target;
int movement;
int len;
int n;
bool pad[10];

int check(int);
void input();
void func();
void output();

int main(){
    input();
    func();
    output();
    return 0;
}

int check(int num){
    if(num == 0){
        if(pad[num]){
            return 1;
        }
        else{
            return 0;
        }
    }
    int cnt = 0;
    while(num){
        int k = num%10;
        if(pad[k]) cnt++;
        else return 0;
        num /= 10;
    }
    return cnt;
}

void func(){
    for(int i=0; i<1000000; i++){
        if(len = check(i)){
            int press = len;
            press += abs(target - i);
            movement = min(movement, press);
        }
    }
}

void output(){
    cout<<movement<<'\n';
}

void input(){
    cin>>target;
    cin>>n;
    memset(pad, true, sizeof(pad));
    for(int i=0; i<n;i++){
        int k; cin>>k;
        pad[k] = false;
    }
    movement = abs(100-target);
}






// #include <bits/stdc++.h>

// using namespace std;

// int pri_value = 100;
// int target;
// int movement = 0;
// int n;
// int pad[10]; //고장패드는 1. 아니면 -1을 가짐.

// void input();
// void func();
// int find_num(int, int);
// void output();

// int main(){
//     input();
//     func();
//     output();
//     return 0;
// }

// int find_num(int move, int tar){
//     if(tar == 0) return move;
//     int k = tar % 10;
//     if(pad[k] == -1){
//         return find_num(move+1, tar/10);
//     }
//     else{
//         int upper = -1; 
//         int lower = -1;
//         for(int i = k+1; i<10; i++){
//             if(pad[i] == -1){
//                 upper = i;
//                 break;
//             }
//         }
//         for(int i= k-1; i>=0; i--){
//             if(pad[i] == -1){
//                 lower = i;
//                 break;
//             }
//         }
//         int cur_move = 550005; // 이론상 나올 수 없는 횟수. (사실상 무한대)
//         if(upper != -1){
//             //올라가서 만난 경우. 내려가서 만난 경우.
//             cur_move = min(find_num(move+1+abs(10-(upper-k)), tar/10 + 1), find_num(move+1+abs(upper-k), tar/10));
//         }
//         if(lower != -1){
//             cur_move = min(find_num(move+1+abs(k-lower), tar/10), find_num(move+1+abs(10-(k-lower)), tar/10-1));
//         }
//         return cur_move;
//     }
// }

// void func(){
//     if(target == pri_value) return;
//     movement = min(movement, find_num(0, target));
// }

// void output(){
//     cout<<movement<<'\n';
// }

// void input(){
//     cin>>target>>n;
//     memset(pad, -1, sizeof(pad));
//     for(int i=0; i<n; i++){
//         int k; cin>>k;
//         pad[k] = 1;
//     }
//     movement = abs(100-target);
// }