#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, k;
long long res = 0;
vector<pair<int, int>> lux;
vector<int> bag;
vector<int> bag_price;
priority_queue<int> can_push_in_top;

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
    cout<<res<<'\n';
}

void func(){
    //기존에는 보석의 위치를 판단.
    //굴러온돌, 박힌돌 상황의 경우에는 박힌돌의 새로운 위치를 찾았음.
    //하지만, 가방을 기점으로, 각 가방에 가장 어울리는 보석을 넣어주면 판단이 가능할듯.
    int j_idx = 0;
    int b_idx = 0;
    while(j_idx < n && b_idx < k){
        if(bag[b_idx] >= lux[j_idx].first){
            //가방에 넣을 수 있다면,
            //후보군에 넣어준다.
            //어차피 여기서 넣을 수 있다면, 뒷 가방에도 넣을 수 있을 것.
            //나중에 pop을 해준다면, 순서대로 들어가도 지장 없는 친구들.
            can_push_in_top.push(lux[j_idx++].second);
        }
        else{
            //넣을 수 있는 상황 종료.
            //해당 자리에 넣을 수 있는 보석의 값의 최대가 저장되어 있을 것. top에.
            if(!can_push_in_top.empty()){
                //현 시점에 해당 가방에 넣을 보석이 있을 때.
                res += can_push_in_top.top();
                can_push_in_top.pop();
            }
            b_idx++;
        }
    }
    //가방 무게 상한에 걸리지 않은 경우.
    // b_idx값이 작고, j_idx값이 n이 이상이 된 경우가 존재할 때,
    // 큐에 쌓인 값들이 뒷 가방들에 배치되면 됨.
    for(int i=b_idx; i < k; i++){
        if(can_push_in_top.empty()) break;
        res += can_push_in_top.top();
        can_push_in_top.pop();
    }
}

void input(){
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int wei , cost;
        cin>>wei>>cost;
        lux.push_back({wei, cost});
    }
    sort(lux.begin(), lux.end());
    for(int i=0; i<k; i++){
        int k; cin>>k;
        bag.push_back(k);
    }
    sort(bag.begin(), bag.end());
    bag_price.resize(bag.size());
    for(int i=0; i<bag_price.size(); i++){
        bag_price[i] = -1;
    }
}