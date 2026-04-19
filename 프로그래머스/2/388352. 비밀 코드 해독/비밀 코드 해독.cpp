#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    vector<int> num(n);
    for(int i=0; i<n; i++){
        num[i] = i+1;
    }
    vector<int> checking(n);
    for(int i=0; i<5; i++){
        checking[i] = 1;
    }
    do{
        
        int flag = 0;
        for(int i=0; i<q.size(); i++){
            int num_cnt = 0;
            for(int j=0; j<n; j++){
                if(checking[j] == 1){
                    auto iter = find(q[i].begin(), q[i].end(), num[j]);
                    if(iter != q[i].end()){
                        num_cnt++;
                    }
                }
            }
            if(num_cnt != ans[i]){
                flag++;
                break;
            }
        }
        if(flag == 0) answer++;
    } while(prev_permutation(checking.begin(), checking.end()));
    return answer;
}