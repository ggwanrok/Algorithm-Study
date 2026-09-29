#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto i : commands){
        vector<int> sub_vec(array.begin()+i[0]-1, array.begin()+i[1]);
        sort(sub_vec.begin(), sub_vec.end());
        answer.push_back(sub_vec[i[2]-1]);
    }
    return answer;
}