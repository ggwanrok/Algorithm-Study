#include <bits/stdc++.h>


using namespace std;
/*
가로로 더 길어지기 위해서는 약수 조합 중에서도 가로 약수가 세로약수 이상이어야 한다.
yellow의 가로 * 2 + 세로 * 2 + 4값이 브라운 값이어야 한다.
그렇게 되면 브라운 값은 가로 + 2, 세로 + 2
*/

vector<int> solution(int brown, int yellow) {
    
    vector<int> answer;
    
    for(int i=1; i<=yellow; i++){
        for(int j=1; j<=i; j++){
            if(i * j != yellow) continue;
            if(i * 2 + j * 2 + 4 != brown) continue;
            answer.push_back(i + 2);
            answer.push_back(j + 2);
            return answer;
        }
    }
    
    return answer;
}