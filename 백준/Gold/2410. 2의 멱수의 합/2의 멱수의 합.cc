#include <iostream>
#include <vector>
#define mod 1000000000
using namespace std;

int n;
vector<int> num;
int main(){
    cin>>n;
    num.resize(n+1, 1);
    for(int i=2; i<=n; i*=2){
        for(int j=1; j<=n; j++){
            if(j-i < 0) continue;
            num[j] += num[j-i];
            num[j] %= mod;
        }
    }
    cout<<num[n]<<'\n';
    return 0;
}