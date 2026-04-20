#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    int cnt = 0;
    int z_cnt = 0;
    
    while(1){
        int cur_cnt = 0;
        for(char iter : s){
            if(iter == '1'){
                cur_cnt++;
            }
            else{
                z_cnt++;
            }
        }
        if(cur_cnt <= 1){
            cnt++;
            break;
        }
        s.clear();
        string tmp = "";
        while(cur_cnt > 0){
            tmp += (cur_cnt%2 + '0');
            cur_cnt /= 2;
        }
        for(int i=tmp.length()-1; i>=0; i--){
            s += tmp[i];
        }
        cnt++;
    }
    
    
    vector<int> answer;
    answer.push_back(cnt);
    answer.push_back(z_cnt);
    return answer;
}