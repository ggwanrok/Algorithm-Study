#include <bits/stdc++.h>

using namespace std;

int n;
int res;

int main(){
    cin>>n;
    res = 0;
    while(n){
        if(n & 1){
            res++;
        }
        n >>= 1;
    }
    cout<<res<<'\n';
    return 0;
}


// int main(){
//     cin>>n;
//     res = 0;
//     while(n){
//         int kk = n % 2;
//         if(kk){
//             res ++;
//         }
//         n /= 2;
//     }
//     cout<<res<<'\n';
//     return 0;
// }