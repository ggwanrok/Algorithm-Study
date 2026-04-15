#include <bits/stdc++.h>

using namespace std;

/*
위상정렬을 해야하나? : 그렇다 : 스케줄표를 관리해야하는 구조이기 때문.
선행조건에 대한 처리를 어케해야하지.

선행작업들이 마무리된 시간을 정리하면 될 것 같은데.
우선 -1로 초기화해둔 뒤,
실행된 녀석은 이전 실행조건 정보 + 해당 스케쥴 소모시간 포함 처리를 진행해서 저장 해주는 방식이면 될 것 같다.


위상정렬을 수행해줄건데,
스케쥴링 될 수 있는 녀석을 수행.
수행하고, 해당 스케쥴이 선행 스케쥴인 스케쥴의 선행조건 해금
+ pre_job 정보에 max 값으로 선행 스케쥴 종료시간 업데이트?
*/

int pre_job_time[10001]; //해당 스케쥴이 최초 수행 : 0, 아닌 값이라면 다른 선행스케쥴의 종료시간.
int job_cost[10001];
int pre_job_cnt[10001]; //선행되어야 하는 스케쥴의 갯수

set<int> pre_job_s[10001]; //[i]를 선행으로 가지는 후대기 스케쥴
set<int> job_s[10001]; //[i]를 수행하기 위해 작업대야 하는 선행 스케쥴
priority_queue<int, vector<int>, greater<int>> scheduler;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n;
    memset(pre_job_time, 0, sizeof(pre_job_time));
    memset(pre_job_cnt, 0, sizeof(pre_job_cnt));
    for(int i=1; i<=n; i++){
        int j_cnt;
        cin>>job_cost[i]>>j_cnt;
        while(j_cnt--){
            int k; cin>>k;
            job_s[i].insert(k);
            pre_job_s[k].insert(i);
            pre_job_cnt[i]++;
        }
    }

    for(int i=1; i<=n; i++){
        if(pre_job_cnt[i] == 0) scheduler.push(i);
    }

    /*
    선행조건이 다 처리된 이제 실행할 수 있는 스케쥴 정보.
    pre-job-time 에서 본인의 정보를 업데이트해준다.
    pre-job-s 에서 남은 요소들에 대해서 본인의 정보에 맞게 후순위에 실행되도록 업데이트 해준다.
    job-s
    */
    while(!scheduler.empty()){
        int cur_job = scheduler.top();
        scheduler.pop();
        pre_job_time[cur_job] += job_cost[cur_job];
        for(auto tmp : pre_job_s[cur_job]){
            pre_job_time[tmp] = max(pre_job_time[tmp], pre_job_time[cur_job]);
            job_s[tmp].erase(cur_job);
            pre_job_cnt[tmp]--;
            if(pre_job_cnt[tmp] == 0){
                scheduler.push(tmp);
            }
        }
    }
    int res = 0;
    for(int i=1; i<=n; i++){
        res = max(res, pre_job_time[i]);
    }
    cout<<res<<'\n';
    return 0;
}