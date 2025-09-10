#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> line;
vector<int> lis;
/*
1자로 서있는 친구들을 순서대로 줄세워야 하는 문제 구조이다.
최대한 움직임이 적기 위해선, 특정 인원들을 고정시키고 나머지 인원을 재배치 해야한다.
lis를 구하자. 해당 인원 수만큼은 더 이동 안해도 됨.
나머지인원들이 1회씩 이동하여 재자리를 찾아가는 것이 최소한의 배치 구성
*/

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; 
    cin>>n;
    line.resize(n);
    for(int i=0; i<n; i++){
        cin>>line[i];
    }
    int var = line[0];
    lis.push_back(var);
    for(int i=1; i<n; i++){
        int tmp = line[i];
        auto iter = lower_bound(lis.begin(), lis.end(), tmp);
        if(iter == lis.end()){
            //tmp가 가장 큰 상황
            lis.push_back(tmp);
        }
        else{
            *iter = tmp;
        }
    }
    cout<<n-lis.size()<<'\n';
    return 0;
}