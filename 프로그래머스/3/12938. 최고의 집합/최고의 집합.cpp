#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(s/n == 0) answer.push_back(-1);
    else{
        for(int i=0; i<n; i++){
            answer.push_back(s/n);
        }
        int tmp = s%n;
        while(1){
            if(tmp <= 0) break;
            for(int i=answer.size()-1; i>=0; i--){
                if(tmp <= 0) break;
                answer[i]++;
                tmp--;
            }
        }
    }
    return answer;
}