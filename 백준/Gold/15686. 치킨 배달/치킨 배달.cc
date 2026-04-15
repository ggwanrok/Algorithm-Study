#include <bits/stdc++.h>

using namespace std;

int n, m;
int res = INT_MAX;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

void input();
void func();
void to_m(vector<pair<int, int>> &, int);
int find_dist(vector<pair<int, int>> &);
void output();

int main(){
    input();
    func();
    output();
    return 0;
}

int find_dist(vector<pair<int, int>> &combi){
    int cur_res = 0;
    for(int i=0; i<house.size(); i++){
        pair<int, int> h1 = house[i];
        int dist = INT_MAX;
        for(int j=0; j<combi.size(); j++){
            int len = abs(combi[j].first-h1.first) + abs(combi[j].second - h1.second);
            dist = min(dist, len);
        }
        cur_res += dist;
    }
    return cur_res;
}


void to_m(vector<pair<int, int>> &combi, int start){  
    if(combi.size() == m){
        res = min(res, find_dist(combi));
        return;
    } 
    for(int i=start; i<chicken.size(); i++){
        combi.push_back(chicken[i]);
        to_m(combi, i+1);
        combi.pop_back();
    }

}

void func(){
    vector<pair<int, int>> combi;
    combi.clear();
    to_m(combi, 0);
}

void input(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int k;
            cin>>k;
            if(k == 2) chicken.push_back({i, j});
            if(k == 1) house.push_back({i, j});
        }
    }
}

void output(){
    cout<<res<<'\n';
}