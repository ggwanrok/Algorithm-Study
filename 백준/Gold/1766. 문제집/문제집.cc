#include <bits/stdc++.h>

using namespace std;

/*
위상정렬 문제.
라고 생각했지만,
같은 진척도라면 수가 더 낮은 문제를 풀이해야하는 조건이 있음.
ㄴ> 우선순위 큐를 사용하여 해결
*/

int n, m;

vector<int> pre_cnt;
vector<int> tree[32002];
vector<int> res;

void input();
void func();
void output();

int main(){
    input();
    func();
    output();
    return 0; 
}

void output(){
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<' ';
    }
}

void func(){
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=1; i<=n; i++){
        if(pre_cnt[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int k = q.top();
        q.pop();
        for(int i=0; i<tree[k].size(); i++){
            pre_cnt[tree[k][i]]--;
            if(pre_cnt[tree[k][i]] <= 0) q.push(tree[k][i]);
        }
        res.push_back(k);
    }
}

void input(){
    cin>>n>>m;
    pre_cnt.resize(n+2);
    
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        tree[a].push_back(b);
        pre_cnt[b]++;
    }
}    