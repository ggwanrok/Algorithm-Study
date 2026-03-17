#include <bits/stdc++.h>

using namespace std;

/*
자카드 유사도는 교집합/합집합의 개념이다.
set 자료구조로는 접근해선 안된다.

두 집합이 모두 공집합일 경우 유사도는 1을 반환한다.

우선 2개의 string 벡터를 만들어준 뒤, 정렬을 해주자.
둘 사이에서 겹치는 요소들의 갯수를 카운트해서 겹치는 갯수가 교집합, 길이 합 - 겹치는 갯수 가 합집함임을 인지하자.

*/

bool is_in(char a){
    if(a < 'a' || a > 'z') return false;
    return true;
}

int solution(string str1, string str2) {
    int answer = 0;
    for(int i=0; i<str1.length(); i++){
        str1[i] = tolower(str1[i]);
    }
    for(int i=0; i<str2.length(); i++){
        str2[i] = tolower(str2[i]);
    }
    vector<string> s1, s2;
    for(int i=0; i<str1.length()-1; i++){
        if(is_in(str1[i]) && is_in(str1[i+1])){
            string tmp = "";
            tmp += str1[i];
            tmp += str1[i+1];
            s1.push_back(tmp);
        }
    }
    for(int i=0; i<str2.length()-1; i++){
        if(is_in(str2[i]) && is_in(str2[i+1])){
            s2.push_back(str2.substr(i, 2));
        }
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
    if(s1.size() == 0 && s2.size() == 0) return 65536;
    //s1, s2에 각 요소들을 정렬해서 넣어 두었다.
    //겹치는 요소 파악하기.
    map<string, int> s1_m;
    map<string, int> s2_m;
    for(int i=0; i<s1.size(); i++){
        if(s1_m.find(s1[i]) != s1_m.end()){
            s1_m[s1[i]]++;
        }
        else{
            s1_m.insert({s1[i], 1});
        }
    }
    for(int i=0; i<s2.size(); i++){
        if(s2_m.find(s2[i]) != s2_m.end()){
            s2_m[s2[i]]++;
        }
        else{
            s2_m.insert({s2[i], 1});
        }
    }
    int intersect_value = 0;
    for(auto iter = s1_m.begin(); iter != s1_m.end(); iter++){
        if(s2_m.find(iter->first) != s2_m.end()){
            intersect_value += min(iter->second, s2_m[iter->first]);
        }
    }
    int union_value = s1.size() + s2.size() - intersect_value;
    double res = (double)intersect_value/union_value;
    answer = (int)(res*65536);
    return answer;
}