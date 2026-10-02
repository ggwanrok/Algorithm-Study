#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
바위 정보가 주어지고, n개만큼 제거한다고 할 때,
남게되는거리의 최소가 가장 큰 것을 구하라.

우선 사잇값을 추출해야해.

*/

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());
    int tmp = 0;
    vector<int> dist;
    for(auto rock : rocks){
        dist.push_back(rock-tmp);
        tmp = rock;
    }
    dist.push_back(distance-tmp);
    
    int le = 1;
    int ri = 500000000;
    while(le <= ri){
        int mid = (le + ri) / 2;
        int cur_rock = 0;
        int cur_sum = 0;
        for(int i=0; i<dist.size(); i++){
            if(mid > dist[i] + cur_sum){
                cur_rock++;
                cur_sum += dist[i];
            }
            else{
                cur_sum = 0;
            }
        }
        if(cur_rock > n){
            ri = mid -1;
        }
        else{
            le = mid +1;
        }
    }
    answer = le-1;
    
    
    return answer;
}