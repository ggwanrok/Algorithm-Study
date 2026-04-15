#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

int n, m, s, t;

//scc 만들 떄 사용할 녀석들
vector<int> orig[10002];
int node_scc[10002];
vector<vector<int>> scc;
int discNum;
int disc[10002];
int groupCount;
stack<int> node_stack;

//만들어진 scc를 통해서 답을 구할 때 사용할 녀석들
int res[10002];
bool visit[10002];

void input();
void make_scc();
int dfs(int);
void use_scc(int, int);

int main(void){
    input();
    make_scc();
    res[node_scc[s]] = scc[node_scc[s]].size();
    use_scc(s, node_scc[s]);
    cout<<res[node_scc[t]]<<'\n';
    return 0;
}

void input(){
    cin>>n>>m>>s>>t;
    for(int i=1; i<=m; i++){
        int start, end;
        cin>>start>>end;
        orig[start].push_back(end);
    }
    fill(disc, disc + sizeof(disc) / sizeof(disc[0]), -1);
    fill(node_scc, node_scc + sizeof(node_scc) / sizeof(node_scc[0]), -1);
}

int dfs(int node){
    disc[node] = discNum++;
    int val = disc[node];
    node_stack.push(node);
    for(int next: orig[node]){
        if(disc[next] == -1) val = min(val, dfs(next));
        else if(node_scc[next] == -1) val = min(val, disc[next]);
    }
    if(val == disc[node]){
        scc.push_back(vector<int>());
        while(true){
            int target = node_stack.top();
            node_stack.pop();

            scc[groupCount].push_back(target);
            node_scc[target] = groupCount;

            if(target == node) break;
        }
        groupCount++;
    }
    return val;
}

void make_scc(){
    for(int i=1; i<= n; i++){
        if(disc[i] == -1) dfs(i);
    }
}

void use_scc(int node, int cur_scc_idx){ // 탐색할 노드와, 해당 노드의 scc 번호를 인자로 받음
    visit[node] = true; //노드 방문을 의미함
    for(int next : orig[node]){ //해당 노드로부터 직접적으로 이어져있는 노드 탐색
        int next_scc_idx = node_scc[next];
        if(next_scc_idx == cur_scc_idx){//이어진 노드가 서로 같은 scc에 속한다면,
            if(visit[next]) continue;//방문여부를 체크하여
            use_scc(next, cur_scc_idx);//방문하지 않았다면, 해당 노드에서도 수행을 해줌
        }
        else{// 서로 다른 scc에 속한다면, 더해줘야함
        // 물론, 더해줬을 때, 값이 줄어드는 경우는 최대의 경우가 아니니깐 패스
            int next_scc_count = scc[next_scc_idx].size();
            int sum = res[cur_scc_idx] + next_scc_count;
            if(sum > res[next_scc_idx]){
                res[next_scc_idx] = sum;
                use_scc(next, next_scc_idx);
            }
        }
    }
}
