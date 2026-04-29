#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    map<int, int> m;
    for(auto iter : tangerine){
        if(m.find(iter) != m.end()) m[iter]++;
        else m.insert({iter, 1});
    }
    vector<pair<int, int>> v;
    for(auto iter : m){
        v.push_back({iter.first, iter.second});
    }
    sort(v.begin(), v.end(), compare);
    int answer = 0;
    for(auto iter : v){
        k -= iter.second;
        answer++;
        if(k <= 0) break;
    }
    return answer;
}
