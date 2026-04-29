#include <bits/stdc++.h>
using namespace std;

/*
정수형 자료 타입 안에서 모두 해결 된다.
결국 에너지를 얼마나 소모해야하는지를 써야 하는 것.

근데 결국 2배씩 커지는 부분이 최대한 많아야하는 것 같은데
*/

int solution(int n)
{
    int ans = 0;
    while(n > 0){
        if(n % 2 != 0) ans++;
        n /= 2;
    }
    
    
    
    return ans;
}