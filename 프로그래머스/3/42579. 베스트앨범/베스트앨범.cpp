#include <string>
#include <vector>
#include <set>
#include <tuple>
#include <algorithm>
#include <iostream>
using namespace std;

/*
장르별 합산 순위 내림차순 정리.
*/

bool compare_1(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

bool compare_2(tuple<string, int, int> a, tuple<string, int, int> b){
    if(get<1>(a) == get<1>(b)){
        return get<2>(a) < get<2>(b);
    }
    return get<1>(a) > get<1>(b);
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    set<string> s;
    vector<pair<string, int>> genre;
    vector<tuple<string, int, int>> each_one;
    for(int i=0; i<plays.size(); i++){
        each_one.push_back({genres[i], plays[i], i});
        if(s.find(genres[i]) != s.end()){
            for(int j=0; j<genre.size(); j++){
                if(genre[j].first == genres[i]){
                    genre[j].second += plays[i];
                }
            }
        }
        else{
            s.insert(genres[i]);
            genre.push_back({genres[i], plays[i]});
        }
    }
    //genre를 통해서 테마별 합산치를 정리했고, each_one을 통해서 순서대로 입력을 받았다.
    sort(genre.begin(), genre.end(), compare_1);
    vector<vector<tuple<string, int, int>>> thema_one;
    thema_one.resize(genre.size());

    for(int i=0; i<genre.size(); i++){
        for(int j=0; j<each_one.size();j++){
            if(get<0>(each_one[j]) == get<0>(genre[i])){
                thema_one[i].push_back(each_one[j]);
            }
        }
    }
    
    for(int i=0; i<thema_one.size(); i++){
        sort(thema_one[i].begin(), thema_one[i].end(), compare_2);
    }
    
    for(int i=0; i<thema_one.size(); i++){
        int loop_value = min(2, (int)thema_one[i].size());
        for(int j=0; j<loop_value; j++){
            answer.push_back(get<2>(thema_one[i][j]));
        }
    }
    
    return answer;
}