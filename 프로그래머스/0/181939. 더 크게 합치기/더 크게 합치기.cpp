#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string aa = to_string(a);
    string bb = to_string(b);
    if(stoi(aa+bb) > stoi(bb+aa)) answer = stoi(aa+bb);
    else answer = stoi(bb+aa);
    return answer;
}