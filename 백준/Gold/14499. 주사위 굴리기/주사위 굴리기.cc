#include <bits/stdc++.h>

using namespace std;

void change_num(int& a, int& b){
    if(b == 0){
        b = a;
    }
    else{
        a = b;
        b = 0;
    }
}

bool can_move(int i, int j, int n, int m, int way){
    if(way == 1){
        if(j+1 >= m) return false;
        return true;
    }
    if(way == 2){
        if(j-1 < 0) return false;
        return true;
    }
    if(way == 4){
        if(i+1 >= n) return false;
        return true;
    }
    if(i-1 < 0) return false;
    return true;
}

int moving(int num, int way){
    if(way == 1){
        num += 3;
        num %= 6;
    }
    if(way == 2){
        num += 4;
        num %= 6;
    }
    if(way == 3){
        num += 2;
        num %= 6;
    }
    if(way == 4){
        num += 5;
        num %= 6;
    }
    return num;
}

int get_nxt_x(int x, int iter){
    if(iter == 4){
        return x+1;
    }
    if(iter == 3){
        return x-1;
    }
    return x;
}

int get_nxt_y(int x, int iter){
    if(iter == 1){
        return x+1;
    }
    if(iter == 2){
        return x-1;
    }
    return x;
}

void update_dice(vector<int>& dice, int way){
    int tmp = dice[5];
    if(way == 1){
        //0-2, 2-5, 5-3, 3-0
        dice[5] = dice[3];
        dice[3] = dice[0];
        dice[0] = dice[2];
        dice[2] = tmp;
    }
    if(way == 2){
        //0-2, 2-5, 5-3, 3-0
        dice[5] = dice[2];
        dice[2] = dice[0];
        dice[0] = dice[3];
        dice[3] = tmp;
    }
    if(way == 3){
        //0-1, 1-5, 5-4, 4-0
        dice[5] = dice[4];
        dice[4] = dice[0];
        dice[0] = dice[1];
        dice[1] = tmp;
    }
    if(way == 4){
        //0-2, 2-5, 5-3, 3-0
        dice[5] = dice[1];
        dice[1] = dice[0];
        dice[0] = dice[4];
        dice[4] = tmp;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m, x, y, k;
    cin>>n>>m>>x>>y>>k;
    vector<vector<int>> area;
    area.resize(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>area[i][j];
        }
    }
    vector<int> command;
    for(int i=0; i<k; i++){
     int input; cin>>input;
     command.push_back(input);
    }

    vector<int> dice(6, 0);
    int dice_floor = 5;
    for(auto iter : command){
        if(can_move(x, y, n, m, iter)){
            update_dice(dice, iter);
            x = get_nxt_x(x, iter);
            y = get_nxt_y(y, iter);
            change_num(dice[5], area[x][y]);
            cout<<dice[0]<<'\n';
        }
    }
    return 0;
}