#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int t, p;
    int shirt[6];
    cin>>n;
    for(int i=0; i<6; i++){
        int k; cin>>k;
        shirt[i] = k;
    }
    cin>>t>>p;

    
    /*
    p장식 묶이는 셔츠는 (p-1)씩 값에 더해준 뒤, 나눠준 몫을 통해서 사야하는 묶음을 계산한다.
    펜은 나눈 몫과 나머지를 출력.
    */
    int t_res = 0;
    for(int i=0; i<6; i++){
        t_res += (shirt[i]+t-1)/t;
    }
    cout<<t_res<<'\n';
    cout<<n/p<<' '<<n%p<<'\n';
    return 0;
}