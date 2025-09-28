#include <bits/stdc++.h>

using namespace std;

/*
입력 :
    추의 갯수
    추 무게 정보
    구슬 갯수
    구슬 무게 정보
*/
/*
첫 추를 사용.
두번쨰부터는 표현 가능한 무게 정보애 대해서
그 추에서 쁠마로 작업을 수행.
*/

queue<int> wei;
set<int> can_wei;
vector<int> ball;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b;
    cin>>a;
    while(a--){
        int k; cin>>k;
        wei.push(k);
    }
    cin>>b;
    while(b--){
        int k; cin>>k;
        ball.push_back(k);
    }


    int wei_var = 0;
    can_wei.insert(wei_var);
    while(!wei.empty()){
        wei_var = wei.front();
        wei.pop();
        set<int> tmp_s;
        for(auto tmp : can_wei){
            tmp_s.insert(wei_var+tmp);
            tmp_s.insert(abs(wei_var-tmp));
        }
        for(auto tmp : tmp_s){
            can_wei.insert(tmp);
        }
        tmp_s.clear();
    }
    
    for(int var : ball){
        if(can_wei.find(var) == can_wei.end()){
            cout<<'N'<<" ";
        }
        else{
            cout<<'Y'<<" ";
        }
    }
    cout<<'\n';

    return 0;
}