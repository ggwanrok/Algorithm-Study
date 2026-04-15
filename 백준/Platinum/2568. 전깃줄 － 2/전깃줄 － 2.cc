#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> LIS;
vector<int> trash;
vector<pair<int, int>> colliPair;

int n;
int P[100001];

void input();
void checkCollision();
void output();

/*
쌍으로 주어지는 input에 대해서, 출발점을 기준으로 오름차순 정렬을 해준 뒤,
LIS 배열을 만들어서 정리해준다면, 만들어지는 LIS 배열의 구성이 바로 가장 긴 혼선위험 없는 경우의 수일 것이다.
*/

int main(void){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    input();
    checkCollision();
    output();

    return 0;
}

void input(){
    cin>>n;
    for(int i=0; i<n; i++){
        int start, end;
        cin>>start>>end;
        colliPair.push_back({start, end});
        }
        
    sort(colliPair.begin(), colliPair.end());
}

void checkCollision(){
    LIS.push_back(colliPair[0].second);

    for(int i=1; i< n; i++){
        if(LIS.back() < colliPair[i].second){
            LIS.push_back(colliPair[i].second);
            P[i] = LIS.size() -1; //P배열은 LIS 배열에서의 인덱스번호를 관리하는 배열
        }
        else{
            //자연스럽게 추가할 수 없는 합선의 경우가 생긴 상태.
            //그렇다면 지금 체크하는 전선이 LIS에 들어간다면 어디가 최적일지를 판단하여 저장하는 구조.
            int index = lower_bound(LIS.begin(), LIS.end(), colliPair[i].second)- LIS.begin();
            LIS[index] = colliPair[i].second;
			P[i] = index;
        }
    }
}

void output(){
    int count = LIS.size(); //사용하는 LIS 의 각 하나씩의 인덱스를 제외하고는 제외해야하는 요소들이다.
    cout<<n - count<<'\n';
    count--;
    //p에 들어가 있는 값들은, 기존 오름차순 pair 벡터에서 LIS에 들어간다면 어디 들어갈 것이냐? 를 저장함.
    //0~n-1의 인덱스를 가지고, 역순으로 돌렸을 때, count의 값과 같은 값을 가지는 P의 인덱스 값이, LIS 이고, 아닌 녀석들이 빠져야하는 녀석들이다.
    for(int i = n-1; i>= 0; i--){
        if(P[i] == count){
            count--;
            continue;
        }
        trash.push_back(colliPair[i].first);
    }
    
    for(int i=trash.size()-1; i>=0; i--){
        cout<<trash[i]<<'\n';
    }
    
}