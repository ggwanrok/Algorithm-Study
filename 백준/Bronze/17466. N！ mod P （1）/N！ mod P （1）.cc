#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, P; cin >> N >> P;
    int res = 1;
    for(int i=1; i<=N; ++i){
        res = (res * (long long)i) % P;

        
    }
    cout << res << '\n';
}
