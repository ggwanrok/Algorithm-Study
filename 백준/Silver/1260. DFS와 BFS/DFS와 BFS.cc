#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int vbfs[1001];//bfs 방문 체크용
int vdfs[1001];//dfs 방문 체크용
vector<int> v[1001];// 그래프

void dfs(int cur){//깊이 우선탐색
    if(vdfs[cur]) return;//이미 방문했으면 종료해준다.
    vdfs[cur] = true;
    cout << cur << " ";
    for(int i = 0; i < v[cur].size(); i++){//해당 수 뒤에 이어진 노드들을 오름차순 정렬해준다.
        sort(v[cur].begin(), v[cur].end());
    }
    for(int i = 0; i < v[cur].size(); i++){//정렬된 수들을 재귀적으로 시행해준다.
        int x = v[cur][i];
        
        dfs(x); 
    }
    
}

void bfs(int cur){//너비 우선 탐색
    queue<int> q;//큐가 사용되는 탐색방식이다.
    q.push(cur);//해당 수를 입력해주고, 방문체크를 해준다.
    vbfs[cur] = true;
    
    while(!q.empty()){//큐가 비어있지 않다면 시행
        int x = q.front();
        q.pop();//해당되는 정점을 출력하고, 큐에서 빼준다.
        
        cout << x << " ";
        
        for(int i = 0; i < v[x].size(); i++){//오름차순 정렬
            sort(v[x].begin(), v[x].end());
        }
    
        for(int i = 0; i < v[x].size(); i++){
            int y = v[x][i];
            
            if(!vbfs[y]){//체크되어있지 않다면, 큐에 입력하고 체크해준다.
                q.push(y);
                vbfs[y] = true;
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);

    int n, m, c;//정점의 갯수, 간선의 갯수, 시작정점
    
    cin >> n >> m >> c;
    
    for(int i = 0; i < m; i++){//이 과정을 통해서 그래프의 노드를 이어준다.(리스트형식)
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
		v[y].push_back(x);
		
    }
   
    dfs(c);
    cout << '\n';
    bfs(c);
    
    return 0;
}
