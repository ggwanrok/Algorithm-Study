#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

int tc;
int n;

int cnt;

int id; //강연결요소 찾는데 사용할 id 번호
int want[100001];
int par[100001];
int is_scc[100001];
stack<int> s;

void input();
void func();
int get_scc(int);
void output();

int main(){
    cin >> tc;
    while(tc--){
        input();
        func();
        output();
    }
    return 0;
}

void output(){
    cout << n - cnt << '\n';
}

int get_scc(int node){
    par[node] = id++;  // 현재 노드의 방문 순서를 기록
    s.push(node);  // 노드를 스택에 저장
    int next = want[node];

    // 아직 방문하지 않은 노드일 경우
    if(par[next] == -1){
        get_scc(next);
    }
    
    // 사이클 여부를 확인 (아직 SCC에 포함되지 않은 노드)
    if(!is_scc[next]){
        if(par[node] == par[next]){
            while(true){
                int top = s.top();
                s.pop();
                is_scc[top] = 1;  // SCC에 포함됨을 표시
                cnt++;
                if(top == node) break;  // 루트 노드까지 처리
            }
        }
        else{
            par[node] = par[next];
        }
    }

    return par[node];
}

void func(){
    for(int i = 0; i < n; i++){
        if(par[i] == -1){
            get_scc(i);
        }
    }
}

void input(){
    memset(want, -1, sizeof(want));
    memset(par, -1, sizeof(par));
    memset(is_scc, 0, sizeof(is_scc));
    cnt = 0;
    id = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> want[i];
        want[i]--; // 0-based 인덱스 사용을 위해 1 감소
    }
}
