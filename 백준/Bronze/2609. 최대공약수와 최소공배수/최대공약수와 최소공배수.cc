#include <iostream>
#include <vector>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    vector <int> A;
    vector <int> B;
    int a, b; cin>>a>>b;
    int t=0;
    int max=0;
    for(int i=1;i<=a;++i){
        if(a%i==0){
            A.push_back(i);
        }
    }
    for(int i=1;i<=b;++i){
        if(b%i==0){
            B.push_back(i);
        }
    }
    for(int i=0;i<A.size();++i){
        for(int j=0;j<B.size();++j){
            if(A[i] == B[j]){
                t = A[i];
            }
            if(t>=max){
                max = t;
            }
        }
    }
    cout<<max<<'\n'<<a*b/max<<'\n';
    return 0;
}