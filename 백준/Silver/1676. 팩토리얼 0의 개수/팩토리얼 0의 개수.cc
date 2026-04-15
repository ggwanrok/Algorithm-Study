#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    int k=2;
    int cnt2=0, cnt5=0;
    while(k<=N){
        cnt2+=N/k;
        k*=2;
    }
    k=5;
    while(k<=N){
        cnt5+=N/k;
        k*=5;
    }
    cout << min(cnt2, cnt5) << '\n';
}
