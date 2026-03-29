#include <bits/stdc++.h>

using namespace std;

/*
어떤 부품 a에 대해서 조합되는 법을 알려준다.
이건 그냥 파서문제가 아닐까?

기본 구현은 쉽다. 이건 아마 메모이제이션이 필요하지 않을까?
역시나 시간초과가 난다.

어떻게 해야 메모이제이션 할 수 있을까

*/

vector<vector<pair<int, int>>> parts;
vector<vector<int>> to_make; //[i]를 만들기 위해서 [j]가 얼만큼필요하다.
vector<int> is_visited;

void get_parts(int a, int n);

int main(){
    int n, m;
    cin>>n>>m;
    parts.resize(n+1);
    to_make.resize(n+1, vector<int>(n+1, 0));
    is_visited.resize(n+1, 0);
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        parts[a].push_back({b, c});
    }

    get_parts(n, n);

    for(int i=1; i<=n; i++){
        if(to_make[n][i] != 0){
            cout<<i<<' '<<to_make[n][i]<<'\n';
        }
    }


    return 0;
}

void get_parts(int a, int n){
    //호출이 되었다는 것은 아직 방문을 안했었다는 것이다. 그럼 이제 수하들을 돔면서 체크해주고 
    for(auto iter : parts[a]){
        if(is_visited[iter.first] == 0){
            //memo
            
            get_parts(iter.first, n);
            
        }
    }

    if(parts[a].size() == 0){
        to_make[a][a] = 1;
    }
    else{
        for(auto iter : parts[a]){
            for(int i=1; i<=n; i++){
                if(to_make[iter.first][i] != 0){
                    to_make[a][i] += to_make[iter.first][i] * iter.second;
                }
            }
        }
    }

    is_visited[a] = 1;
}