#include <bits/stdc++.h>

using namespace std;

int n, target;
vector<int> v;

int main(){
    cin >> n;
    v.resize(n);
    
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> target;

    sort(v.begin(), v.end());

    int p1 = 0, p2 = n - 1;  
    int res = 0;

    while (p1 < p2) {
        int cur = v[p1] + v[p2];

        if (cur == target) {
            res++;
            p1++;
        }
        else if (cur < target) {  
            p1++;  
        }
        else {  
            p2--; 
        }
    }
    
    cout << res << '\n';
    return 0;
}
