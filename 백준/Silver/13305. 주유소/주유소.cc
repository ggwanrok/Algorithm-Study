/*
위치한 노드의 코스트보다 작게 소모하는 지점에 도달할 때까지 주유를 하기.
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
vector<ll> edge;
vector<ll> city;

int main(){
    cin>>n;
    for(int i=0; i<n-1; i++){
        int k; cin>>k;
        edge.push_back(k);
    }
    for(int i=0; i<n; i++){
        int k; cin>>k;
        city.push_back(k);
    }

    ll res = 0;
    int idx = 0;
    ll cost = city[idx];
    while(idx < n-1){
        int iter = idx;
        int end_point = -1;
        for(int i=iter; i<n; i++){
            if(city[i] < cost){
                end_point = i;
                break;
            }
        }
        if(end_point == -1){
            //해당 코스트로 끝까지 진행
            int loop = 0;
            for(int i=idx; i<n-1; i++){
                loop += edge[i];
            }
            res += (cost * loop);
            break;
        }
        else{
            int loop = 0;
            for(int i=idx; i<end_point; i++){
                loop += edge[i];
            }
            res += (cost * loop);
            idx = end_point;
            cost = city[idx];
        }
    }

    cout<<res<<'\n';

    return 0;
}