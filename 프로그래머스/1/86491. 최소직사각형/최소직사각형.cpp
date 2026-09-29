#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int min_i = 0;
    int min_j = 0;
    for(auto s : sizes){
        int min_value = min(s[0], s[1]);
        int max_value = max(s[0], s[1]);
        min_i = max(min_i, min_value);
        min_j = max(min_j, max_value);
    }
    return min_i*min_j;
}