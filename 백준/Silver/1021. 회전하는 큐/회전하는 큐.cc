#include <bits/stdc++.h>

using namespace std;

int solution(int n, int loop, vector<int> tar);

int main(){
    int n; int loop;
    cin>>n>>loop;
    vector<int> target;
    for(int i=0; i<loop; i++){
        int k; cin>>k;
        target.push_back(k);
    }
    cout<<solution(n, loop, target)<<'\n';
    return 0;
}

int solution(int n, int loop, vector<int> tar){
    int answer = 0;

    deque<int> li;
    for(int i=0; i<n; i++){
        li.push_back(i+1);
    }

    
    for(int cur_tar:tar){
        int idx = 0;
        for(int i = 0; i < li.size(); i++){
            if(li[i] == cur_tar){
                idx = i;
                break;
            }
        }

        int left_dist = idx; 
        int right_dist = li.size() - idx; 

        if(left_dist <= right_dist){
            while(li.front() != cur_tar){
                li.push_back(li.front());
                li.pop_front();
                answer++;
            }
        }
        else{
            while(li.front() != cur_tar){
                li.push_front(li.back());
                li.pop_back();
                answer++;
            }
        }
        
        li.pop_front();

    }

    return answer;
}