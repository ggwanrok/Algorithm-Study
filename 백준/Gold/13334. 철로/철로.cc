#include <bits/stdc++.h>

using namespace std;

int n;
int rail;
vector<pair<int, int>> v;


bool compare(const pair<int,int>& a,const pair<int,int>& b ){
    if(a.second == b.second)
      return a.first < b.first;
    
    return a.second < b.second;
  }

void input(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    vector<pair<int, int>> tmp;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        if(a > b) swap(a, b);
        tmp.push_back({a, b});
    }
    cin>>rail;
    for(auto cur : tmp){
        int cur_1 = cur.first;
        int cur_2 = cur.second;
        if(cur_2 - cur_1 > rail) continue;
        v.push_back(cur);
    }
    sort(v.begin(), v.end(), compare);
    //후항에 대해서 더 작은 값을 기준으로 정렬. 
}

void func(){
    //1차적으로 걸러진 pair들을 기준을 문제를 해결하자.
    priority_queue<int, vector<int>, greater<>> pq;
    int max_cnt = 0;
    for(auto cur : v){
        pq.push(cur.first);

        while(!pq.empty() && pq.top() < cur.second - rail){
            pq.pop();
        }
        max_cnt = max(max_cnt, (int) pq.size());
    }
    cout<<max_cnt<<'\n';
}

int main(){
    input();
    func();
    return 0;
}
