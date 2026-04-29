#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

/*
무조건 최대 두명의 상한.
우선 가장 뚱뚱이 먼저.
그리고 가장 끝 녀석을 넣을 수 있으면 넣고 아님 말고

*/

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), greater());
    deque<int> d;
    for(auto iter : people){
        d.push_back(iter);
    }
    while(!d.empty()){
        int value = d.front();
        d.pop_front();
        answer++;
        if(!d.empty() and value + d.back() <= limit){
            d.pop_back();
        }
    }
    return answer;
}