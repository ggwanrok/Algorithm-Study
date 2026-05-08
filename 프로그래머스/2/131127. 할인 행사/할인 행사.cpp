#include <bits/stdc++.h>

using namespace std;

/*
슬라이딩 윈도우 문제.
길이가 10 이하라면 체크해주면서 확장.

논리체계를 잡아보자.

조건을 만족하는 슬라이딩 윈도우를 구축하여 해당 기간동안 모두 장바구니에 담는다.
할인하지 못하고 사는 품목은 음수가 된다. 하지만 상관없다.
이렇게 해야 left로 빠지는 놈에 대해서 무분별하게 할인상품 품목 취급해서 뺄 일이 사라진다.
list정보가 양수인 것이 하나도 없다면 해당 항목들을 모두 할인받는다는 뜻이기 때문이다.

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