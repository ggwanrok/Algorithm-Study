#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<int> v(n+1, 0);
    v[1] = v[2] = 1;
    for(int i=2; i<=n; i++){
        v[i] = (v[i] + v[i-1] + v[i-2])%1234567;
    }
    answer = v[n];
    return answer;
}