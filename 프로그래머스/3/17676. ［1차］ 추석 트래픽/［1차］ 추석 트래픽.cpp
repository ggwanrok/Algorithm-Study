#include <bits/stdc++.h>

using namespace std;

/*
pair 단위의 도입부 정렬 후,
우선순위 큐는 뒷부분 우선으로 하면 될듯.

새로 넣을 때, 남이있는 놈들 중에서 뺼놈들 빼주고
넣고 크기 측정하는 방식으로 하면 될듯


*/

struct compare {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second; // second 기준 최소 힙 (작은 게 위로)
    }
};

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int, int>> shed;
    for(string line : lines){
        string line1 = line.substr(11, 12);
        string line2 = line.substr(24);
        line2 = line2.substr(0, line2.length()-1);
        int value2 = stoi(line1.substr(0, 2))*3600*1000;
        value2 += stoi(line1.substr(3, 2))*60*1000;
        value2 += stoi(line1.substr(6, 2))*1000;
        value2 += stoi(line1.substr(9, 3));
        int term = (line2[0]-'0')*1000;
        if(line2[1] == '.'){
            string tmp = line2.substr(2);
            tmp = tmp.substr(0, tmp.length());
            while(tmp.length()<3) tmp += "0";
            term += stoi(tmp);
        }
        int value1 = value2-term+1;
        shed.push_back({value1, value2});
    }
    
    sort(shed.begin(), shed.end());
    priority_queue<pair<int,int>, vector<pair<int, int>>, compare> pq;
    
    for(auto iter : shed){
        while(!pq.empty() and pq.top().second + 1000 <= iter.first){
            pq.pop();
        }
        pq.push(iter);
        answer = max(answer, (int)pq.size());
    }
    
    return answer;
}