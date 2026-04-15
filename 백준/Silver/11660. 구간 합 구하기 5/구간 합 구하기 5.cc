#include <iostream>
using namespace std;
int s[1030][1030];
int f(int x, int y, int x2, int y2){
    int sum =0;
   for(int i = x; i<=x2; ++i){
        sum = sum + s[i][y2] - s[i][y-1];
   }
   return sum;
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int n, t; cin>>n>>t;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            int k; cin>>k;
            s[i][j] = s[i][j-1]+k;
        }
    }
    for(int i=0; i<t; ++i){
        int x, y, x2, y2;
        cin>>x>>y>>x2>>y2;
        cout<<f(x, y, x2, y2)<<'\n';
    }
    return 0;
}