#include <bits/stdc++.h>

using namespace std;

/*
슬라이딩 윈도우 문제.
길이가 10 이하라면 체크해주면서 확장.

논리체계를 잡아보자.

right 의 대상이 채워줘야 하는 놈 -> 길이적 여유가 있는가?, 갯수적 여유가 있는가?
right 의 대상이 필요 없는 놈 -> 길이적 여유가 있는가?(그냥 늘림)
*/

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    map<string, int> list;
    for(int i=0; i<want.size(); i++){
        list.insert({want[i], number[i]});
    }
    map<string, int> tmp = list;
    
    int left, right;
    left = 0;
    right = 0;
    int cur_value=0;
    for(right=0; right<discount.size(); right++){
        if(right-left >= 10){ //길이가 10일 때는 무조건 늘림
                if(list.find(discount[left]) != list.end()){
                    list[discount[left]]++;
                    cur_value--;
                }
                if(list.find(discount[right]) != list.end()){
                    list[discount[right]]--;
                    cur_value++;
                }
                left++;
            }
        else{ //길이는 여유가 있다. 그렇다면 그냥 늘려
                if(list.find(discount[right]) != list.end()){
                    list[discount[right]]--;
                    cur_value++;
                }
            }
        int flag_cnt = 0;
        for(auto iter : list){
            if(iter.second <= 0) flag_cnt++;
        }
        if(flag_cnt >= list.size()) answer++;
        
    }
    
    return answer;
}