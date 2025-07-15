#include <iostream>
using namespace std;
int d[3];
int d2[3];
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int n; cin>>n;
    for(int i=0; i<3; ++i){
        cin>>d[i];
        d2[i] = d[i];
    }
    for(int i=0; i<n-1; ++i){
        int a, b, c;
        cin>>a>>b>>c;
        int fB = max(d[0], d[1]) + a;
        int fS = min(d2[0], d2[1]) + a;

        int sB = max(d[0],max(d[1], d[2])) + b;
        int sS = min(d2[0],min(d2[1], d2[2])) + b;

        int tB = max(d[1], d[2]) + c;
        int tS = min(d2[1], d2[2]) + c;

        d[0] = fB;
        d[1] = sB;
        d[2] = tB;
        d2[0] = fS;
        d2[1] = sS;
        d2[2] = tS;
    }
    int t = max(d[0], max(d[1], d[2]));
    int t2 = min(d2[0], min(d2[1], d2[2]));
    cout<<t<<" "<<t2;
    return 0;
} 
