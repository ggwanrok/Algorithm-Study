#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(tuple<int, int, int> a, tuple<int, int, int> b){
    return get<2>(a) < get<2>(b);
}

int find_par(int a, vector<int> & p){
    if(a == p[a]){
        return a;
    }
    return p[a] = find_par(p[a], p);   
}

void union_par(int a, int b, vector<int> & p){
    if(find_par(a, p) == find_par(b, p)) return;
    if(a > b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    p[find_par(b, p)] = find_par(a, p);
    find_par(b, p);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<tuple<int,int,int>> v;
    for(auto cost : costs){
        v.push_back({cost[0], cost[1], cost[2]});
    }
    sort(v.begin(), v.end(), compare);
    
    vector<int> par;
    for(int i=0; i<n; i++){
        par.push_back(i);
    }
    
    for(auto tu : v){
        int a = get<0>(tu);
        int b = get<1>(tu);
        int cost = get<2>(tu);
        if(find_par(a, par) != find_par(b, par)){
            union_par(a, b, par);
            answer += cost;
        }
    }
    return answer;
}