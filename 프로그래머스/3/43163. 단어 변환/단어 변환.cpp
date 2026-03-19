#include <bits/stdc++.h>

using namespace std;

/*
begin 이 word의 있는 한개의 차이 단어로 변환될 수 있고 결국 target에 도달해야 한다.

최소 몇 단계의 과정을 거쳐 -> bfs 고려하기.
ㅇㅋ 그럼 될듯.
처음에 문자열 통으로 큐에 넣고, visited 써서
*/

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int cur_cnt = 0;
    map<string, int> is_visited;
    for(auto word : words){
        is_visited.insert({word, -1});
    }
    if(is_visited.find(begin) != is_visited.end()){
        is_visited[begin] = 0;
    }
    else{
        is_visited.insert({begin, 0});
    }
    queue<string> q;
    q.push(begin);
    while(!q.empty()){
        string cur = q.front();
        q.pop();
        if(cur == target){
            answer = is_visited[cur];
            break;
        }
        for(auto iter : words){
            if(is_visited[iter] == -1){
                int cnt_diff = 0;
                for(int i=0; i<iter.size(); i++){
                    if(cur[i] != iter[i]) cnt_diff++;
                }
                if(cnt_diff == 1){
                    is_visited[iter] = is_visited[cur]+1;
                    q.push(iter);
                }
            }
        }
    }
    
    return answer;
}