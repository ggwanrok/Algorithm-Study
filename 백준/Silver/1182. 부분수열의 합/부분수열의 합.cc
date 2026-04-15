#include <bits/stdc++.h>
using namespace std;

int n, s;
int v[25]; 
int res;

void dfs(int idx, int sum){
    if(idx == n){
        if(sum == s) res++;
        return;
    }
    dfs(idx + 1, sum + v[idx]);
    dfs(idx + 1, sum);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    res = 0;
    dfs(0, 0);

    if(s == 0) res--;

    cout << res << '\n';
    return 0;
}
