#include <bits/stdc++.h>

using namespace std;

int n, m;
int res[1001];
vector<vector<int>> v;

void input(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    v.resize(n+1);
    fill(res, res + 1001, 1);

    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        v[a].push_back(b);
    }
}

void func(){
    // 진입차수 계산
    vector<int> indegree(n + 1, 0);
    for(int i = 1; i <= n; i++){
        for(int next : v[i]){
            indegree[next]++;
        }
    }

    queue<int> q;
    // 진입차수 0인 노드(=선수과목 없는 과목)를 큐에 넣음
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int next : v[cur]){
            indegree[next]--;
            // 선수 과목(cur)을 다 들었으므로 학기 업데이트
            res[next] = max(res[next], res[cur] + 1);
            if(indegree[next] == 0){
                q.push(next);
            }
        }
    }
}


void output(){
    for(int i=1; i<=n; i++){
        cout<<res[i]<<' ';
    }
    cout<<'\n';
}

int main(){
    input();
    func();
    output();
    return 0;
}