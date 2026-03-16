#include <bits/stdc++.h>

using namespace std;

/*
(쟁점) 스케쥴 부여의 판단 기준을 무엇으로 삼을 것이냐?

유형별로 각각 몇명을 배치하는 것이 적절한 것인가? 를 따져보면 될 것 같다.
모두 계산하는 것이 아니라, 각 유형별로 한명씩 늘렸을 때, 낭비되는 시간을 계산하여 가지도록 한다.
그렇게 해서 인원의 합이 n이 되는 경우에서 합의 최소를 answer에 담아서 리턴한다.

결국 각 유형은 서로에게 영향을 끼치지 못하기에, 독립적인 요소로 바라보고 판단을 하며,
인원 분배에 따른 최적의 경우만 가지고 놀면 된다.

해당 유형에 인원배치를 1명했을 때부터, n명 했을때까지로 두고 최솟값을 가지는 경우를 잡게 한다.
이론상 낭비되는 각 합산치의 최대인 6000즈음보다 훨씬 큰 10000 정도로 초깃값을 두고 갱신하도록 각 배열을 채워보자.
*/

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = INT_MAX;
    vector<vector<pair<int, int>>> each_mento(k+1);
    for(auto iter : reqs){
        int start_time = iter[0];
        int run_time = iter[1];
        int category = iter[2];
        each_mento[category].push_back({start_time, run_time});
    }    
    /*each_mento 에 각 인덱스는 카테고리 번호이다. 
    1부터 k까지의 카테고리를 [담당멘토가 1~n명일 때의 회의실 문제]로 바라보자.*/
    vector<vector<int>> waste_time(k+1, vector<int>(n+1, 10000000));
    for(int i=1; i<=k; i++){
        //각 i에 대한 each_mento를 따라가며 이후 나올 j의 값에 따른 문제 풀이 진행.
        //회의실 문제도 아니다. 어차피 오는 순서대로 넣는다. 이럼 계산도 더 편해.
        if(each_mento[i].size() == 0){ //해당 유형이 없다면 낭비시간이 0이다.
            for(int j=1; j<=n; j++){
                waste_time[i][j] = 0;
            }
            continue;
        }
        for(int j=1; j<=n; j++){
            int cur_waste = 0;
            priority_queue<int, vector<int>, greater<int>> cur_mento;
            for(int c=0; c<each_mento[i].size(); c++){
                int cur_start_time = each_mento[i][c].first;
                int cur_run_time = each_mento[i][c].second;
                //바로 사용할 수 있는가? 사용할 수 있는 이후시간을 넣어준다.
                if(cur_mento.size() < j){
                    cur_mento.push(cur_start_time+cur_run_time);
                }
                //사용할 수 없는가?
                else{
                    //낭비가 없는가
                    if(cur_mento.top() <= cur_start_time){
                        cur_mento.pop();
                        cur_mento.push(cur_start_time+cur_run_time);
                    }
                    //낭비가 있는가
                    else{
                        cur_waste += (cur_mento.top() - cur_start_time);
                        int nxt_time = cur_mento.top();
                        cur_mento.pop();
                        cur_mento.push(nxt_time+cur_run_time);
                    }
                }
            }
            waste_time[i][j] = cur_waste;
        }
    }
    //i개의 유형에 따른 j명의 상담사의 배치표는 waste_time으로 준비되어 있음.
    //그럼 이제 여기서 디피를 써야하는건가?
    //i번째 유형까지 고려했을 때, j명의 상담사가 참여했을 때 소모되는 시간을 저장하도록 하자.
    vector<vector<int>> dp(k+1, vector<int>(n+1, 10000000));
    for(int j=1; j<=n; j++){
        dp[1][j] = waste_time[1][j];
    }
    for(int i=2; i<=k; i++){
        for(int j=i; j<=n; j++){
            for(int z=1; z<j; z++){ //각 유형당 1명씩은 배치되어야 하기에 범위 설정 주의
                //i유형까지 확장하며, j명의 상담사가 배치될 때, i유형에 배치되는 상담사의 수 z
                //j-z의 값이 i-1이상이어야 한다. 이미 한명씩 배치되어야 하기에.
                dp[i][j] = min(dp[i][j], waste_time[i][z] + dp[i-1][j-z]);
            }
        }
    }
    
    answer = dp[k][n];
    return answer;
}