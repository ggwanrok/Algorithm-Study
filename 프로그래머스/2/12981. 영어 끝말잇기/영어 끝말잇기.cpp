#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    char last = '-';
    int person_loop = 1;
    int person_cnt = 1;
    for(auto cur : words){
        if(last != '-' and last != cur[0] or s.find(cur) != s.end()){
            answer.push_back(person_cnt);
            answer.push_back(person_loop);
            break;
        }
        person_cnt++;
        if(person_cnt > n){
            person_loop++;
            person_cnt = 1;
        }
        s.insert(cur);
        last = cur[cur.length()-1];
    }
    if(answer.size() == 0){
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}