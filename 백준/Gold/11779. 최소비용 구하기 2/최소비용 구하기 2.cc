#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int n, m;
int cost[1003][1003];
bool wayConfir[1003];
int dijkstra[1003];
int wayFrom[1003];


void cleanCost();
void dijkstraAlgo(int, int);

int main(void){
    cin>>n>>m;
    stack<int> checkStack;
    cleanCost();
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        cost[a][b] = (cost[a][b] > c) ? c : cost[a][b];
    }

    int start, end;
    cin>>start>>end;
    
//여기까지 해서, 필요한 인풋들을 받아내는 작업을 진행해줬다.
//시작점으로 부터 진행을 해주고, end포인트에 도달하게 된다면, 종료시킨다.
//사실 이쁘게 작업하기 위해서는, 위 배열들을 구조체화 시켜서 작업해봐도 좋을 것 같다.
    wayFrom[start] = -1;
    wayConfir[start] = true;
    dijkstra[start] = 0;

    dijkstraAlgo(start, end);
//알고리즘 수행이 종료되었다.

    cout<<dijkstra[end]<<'\n'; // 첫줄 출력

    checkStack.push(end);
    int stackIndex = end;

    while(wayFrom[stackIndex] != -1){
        checkStack.push(wayFrom[stackIndex]);
        stackIndex = wayFrom[stackIndex];
    }

    int wayLength = checkStack.size();
    cout<<wayLength<<'\n';

    while(!checkStack.empty()){
        cout<<checkStack.top()<<' ';
        checkStack.pop();
    }
    
    


    return 0;
}

void cleanCost(){ // 초기상태를 만들어주기 위해서 작성한 함수.
    for(int i=1; i<=n; i++){
        wayConfir[i] = false;
        dijkstra[i] = 200000000;
        for(int j=1; j<=n; j++){
            cost[i][j] = 200000000;
        }
    }
}

void dijkstraAlgo(int start, int end){ //다익스트라 알고리즘을 수행하는 함수이다.
    int smaller, smalleridx;
    smaller = 200000000;
    smalleridx = 1002;
    for(int i=1; i<=n; i++){
        if(wayConfir[i] == false && dijkstra[i] > cost[start][i] + dijkstra[start]){
            dijkstra[i] = cost[start][i] + dijkstra[start];
            wayFrom[i] = start;
        }
    }
    for(int i=1; i<=n; i++){
        if(wayConfir[i] == false){
            if(smaller > dijkstra[i]){
                smaller = dijkstra[i];
                smalleridx = i;
            }
        }
    }
    wayConfir[smalleridx] = true;
    if(smalleridx != end){
        dijkstraAlgo(smalleridx, end);
    }
    
}