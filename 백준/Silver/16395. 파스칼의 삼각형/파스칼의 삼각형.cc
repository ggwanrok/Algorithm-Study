#include <bits/stdc++.h>

using namespace std;

/*
    1
   1 1
  1 2 1
 1 3 3 1 
1 4 6 4 1
combination prob.
*/
int c[35][35];
int n, k;

int get_c(int a, int b){
    if(a <= 0 or b <= 0) return 1;
    if(c[a][b] > 0) return c[a][b];
    return c[a][b] = get_c(a-1, b) + get_c(a-1, b-1);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    n--;
    k--;
    for(int i=1; i<=30; i++){
        c[i][1] = i;
        c[i][i] = 1;
    }
    cout<<get_c(n, k)<<'\n';
    return 0;   
}