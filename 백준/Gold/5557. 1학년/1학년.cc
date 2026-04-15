#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

int n;
ll v[105];
ll ddp[105][21];

ll dp(ll value, ll index){
    if(value > 20 || value < 0) return 0;

    ll &ret = ddp[index][value];
    if(ret) return ret; // 이미 저장된 값이 있다면, 그것을 리턴한다.(여기선 1이 리턴됨)

    if(index == n-1){
        if(value == v[0]) return 1;

        return 0;
    }
    ret += dp(value + v[index+1], index+1);
    ret += dp(value - v[index+1], index+1);

    return ret;
}

int main(void){
    cin>>n;

    for(int i=1; i<n; i++){
        int k;
        cin>>k;
        v[i] = k;
    }
    int k;
    cin>>k;
    v[0] = k;
    //v 내부에 연산에 필요한 값을 저장하고, 연산을 진행한다.
    //만약, 연산 진행 도중, 20을 넘어가거나, 음수가 되었을 경우, 해당 진행을 종료한다.
    //해당 연산에서 다음 연산은 다음챕터의 값을 더하거나 빼주는 과정을 진행하도록 한다.
    //벡터의 끝까지 진행을 했을 때, 0번 인덱스와 값이 같다면, ++을 해준다.
    
    //값을 덮어쓰는 것을 방지하기 위해서, 함수는
    //현재까지 진행된 값과, 진행중인 인덱스가 넘어가고,
    //인덱스가 끝이 아니라면, 다음 녀석을 더하거나 빼주는 형식의 재귀가 진행되어야 할 것 같다.
    cout<<dp(v[1], 1)<<'\n';



    return 0;
}