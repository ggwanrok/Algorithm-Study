#include <string>
#include <iostream>
#include <vector>

/*
인원수 체크가 되는 기간마다 점검해야 할 것.

현재 인원수에 대한 필요한 서버의 수 : players[i]/m
i-k 가 0 이상일 때, 체크해야할 것 : 이번 차례에 꺼지는 서버의 갯수
-> 이를 반영하여 이번 자리에서 켜져야 하는 거버의 갯수 : addition_server[i]
매 순간 k만큼의 뒤 증설 여부를 확인하며 처리하면 될 것 같은데.
직전에 켜진 것에 대한 갯수에서 이번에 꺼지는 것의 갯수를 고려 후, 이번에 새로 켜져야 하는 것에 대한 처리.
*/

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> current_server(players.size(), 0);
    vector<int> addition_server(players.size(), 0);
    current_server[0] = players[0]/m;
    addition_server[0] = current_server[0];
    answer += addition_server[0];
    //위와 같이 초깃값 설정 완료.
    for(int i=1; i<players.size(); i++){
        int need_server = players[i]/m; //현시점 필요한 서버의 수
        int can_use_server = current_server[i-1]; //현시점 사용가능한 서버의 수
        if(i-k >= 0){
            can_use_server -= addition_server[i-k]; //이번에 꺼지는 것을 제외
        }
        if(need_server <= can_use_server){
            current_server[i] = can_use_server;
            addition_server[i] = 0;
            continue;
        }
        int new_server = need_server-can_use_server; //필요한 새로운 서버의 갯수
        addition_server[i] = new_server; //증설되는 새로운 서버
        current_server[i] = need_server;
        answer += new_server;
        
    }
    
    return answer;
}