#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    a--;
    b--;
    int cnt = 1;
    while(1){
        if(a == b){
            answer = cnt-1;
            break;
        }
        cnt++;
        a /= 2;
        b /= 2;
    }    
    return answer;
}