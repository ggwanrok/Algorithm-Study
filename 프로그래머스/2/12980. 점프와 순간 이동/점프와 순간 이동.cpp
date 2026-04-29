#include <bits/stdc++.h>
using namespace std;


int solution(int n)
{
    int ans = 0;
    // while(n > 0){
    //     if(n % 2 != 0) ans++;
    //     n /= 2;
    // }
    while(n){
        if(n & 1) ans++;
        n = n >> 1;
    }
    
    
    
    return ans;
}