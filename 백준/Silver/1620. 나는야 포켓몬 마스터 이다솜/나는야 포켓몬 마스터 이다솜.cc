#include <iostream>
#include <map>
#include <string>
using namespace std;
string arr[100001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin>>n>>m;
    map <string, int> c;
    for(int i=1; i<=n; ++i){
        string s; cin>>s;
        c[s] = i;
        arr[i] = s;
    }
    
    for(int i=0; i<m; ++i){

        string k; cin>>k;
        int d = atoi(k.c_str());
        if(isdigit(k[0])==0){
            cout<<c[k]<<'\n';
        }
        else{
            cout<<arr[d]<<'\n';
        }
    }
    return 0;
    //c_str() 은 c++에서 string를 char*로 변환해주는 함수이다.
    //isdigit은 숫자이면 0이 아닌 값을 반환, 숫자가 아니면, 0을 반환한다.
}