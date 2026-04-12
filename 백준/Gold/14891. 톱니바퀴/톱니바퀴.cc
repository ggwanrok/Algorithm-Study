#include <bits/stdc++.h>

using namespace std;

/*
각 톱니바퀴의 최상단 인덱스 기준을 확보한다.
운동 방향에 따른 시계방향, 반시계방향 파라미터를 정한다.
파라미터로 돌려야 하는 놈의 최상단 놈 인덱스
*/


vector<vector<int>> v;
vector<int> v_top;

void func(vector<vector<int>>& v, int way, int target, int prev, vector<int> &v_top){
    //로직 짜기
    //+2, +6
    if(target < 3 && prev != target+1 && v[target][(v_top[target]+2)%8] != v[target+1][(v_top[target+1]+6)%8]){
        //진행 가능
        //재귀 호출하고 변동 작업해주기
        func(v, way*-1, target+1, target, v_top);
        
    }
    if(target > 0 && prev != target -1 && v[target][(v_top[target]+6)%8] != v[target-1][(v_top[target-1]+2)%8]){
        //진행 가능
        func(v, way*-1, target-1, target, v_top);
        
    }
    if(way == -1){
        v_top[target] = (v_top[target]+1)%8;
    }
    if(way == 1){
        v_top[target] = (v_top[target]+7)%8;
    }

}

int main(){
    v_top.resize(4, 0);
    v.resize(4, vector<int>(8));

    for(int i=0; i<4; i++){
        string s;
        cin>>s;
        for(int j=0; j<8; j++){
            v[i][j] = s[j]-'0';
        }
    }

    int tc;
    cin>>tc;

    while(tc--){
        
        int start, way;
        cin>>start>>way;
        func(v, way, start-1, -2, v_top);
        
    }
    int res = 0;
    for(int i=0; i<4; i++){
        res += v[i][v_top[i]] * (int)pow(2, i);
    }
    cout<<res<<'\n';
    return 0;
}