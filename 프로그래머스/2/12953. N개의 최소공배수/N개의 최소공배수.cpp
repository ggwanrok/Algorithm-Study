#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int get_gcd(int a, int b){
    if(b == 0) return a;
    return get_gcd(b, a%b);
}

int get_lcm(int a, int b){
    int c = get_gcd(a, b);
    return a*b/c;
}

int solution(vector<int> arr) {
    int answer = 0;
    priority_queue<int> q;
    for(auto iter : arr) q.push(iter);
    while(q.size() > 1){
        int num1 = q.top();
        q.pop();
        int num2 = q.top();
        q.pop();
        q.push(get_lcm(num1, num2));
    }
    answer = q.top();
    return answer;
}