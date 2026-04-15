#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int city[105][105];

void input();
void floyd_warshall();
void output();

int main(){
    /*
    각 도시의 간선정보를 우선 최저로 업데이트해주며 저장.
    간선정보가 없으면 -1의 값을 가짐.
    이중for문 구조를 통해서 각 인덱스로의 플로이드-워셜 알고리즘을 구현하면 될듯.
    */
    input();
    floyd_warshall();
    output();

    return 0;
}

void floyd_warshall(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                // if(city[i][j] == -1 || city[i][k] == -1 || city[k][j] == -1) continue;
                if(city[i][j] > city[i][k] + city[k][j]) city[i][j] = city[i][k] + city[k][j];
            }
        }
    }
}

void input(){
    cin>>n>>m;

    for(int i = 1; i <= n; i++) {
        fill(city[i] + 1, city[i] + n + 1, 100000000);
        city[i][i] = 0;
    }


    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(city[a][b] == 100000000) city[a][b] = c;
        else{
            city[a][b] = min(city[a][b], c);
        }
        
    }
}

void output(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(city[i][j] == 100000000) cout<<0;
            else cout<<city[i][j];
            cout<<" ";
        }
        cout<<'\n';
    }
}