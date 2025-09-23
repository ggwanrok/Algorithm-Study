#include <bits/stdc++.h>

using namespace std;
/*
오른쪽의 입력값이 현재의 입력값보다 큰 것이 있을 때,
가장 왼쪽에 있는 수를 오큰수라고 한다.

현재 바라보는 위치에서의 오큰수를 어떤식으로 판단할 것이냐
-> 우선 입력을 받은 뒤 오늘쪽 끝부터 뭔가를 해ㅑㅇ하지않을까?
오른쪽에서부터 진행하여,
오큰수의 오큰수 -> 이런 방식으로 진행해야 할 것 같은데?
4
3 5 2 7
이라면 
7에 대한 오큰수는 -1
2는 다음 녀석에 대한 7이 오큰수냐? 
-> yes : 오큰수로 7 등록
-> no : 7의 오큰수가 있냐?
    -> yes : 그 수가 2의 오큰수를 만족하냐?
        -> yes : 오큰수로 그 녀석 등록
        -> no : 재귀
    -> no : 너 정보도 -1 등록
*/

int n; 
vector<int> input_arr;
int nge[1000001];
stack<int> res;

int get_nxt_nge(int tar, int val){
    if(tar < val){
        return nge[tar] = val;
    }
    if(nge[val] == -1){
        return nge[tar] = -1;
    }
    else{
        return nge[tar] = get_nxt_nge(tar, nge[val]);
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        input_arr.push_back(k);
    }
    memset(nge, 0, sizeof(nge));
    res.push(-1);
    nge[input_arr[input_arr.size()-1]] = -1;
    for(int i=input_arr.size()-2; i>=0; i--){
        res.push(get_nxt_nge(input_arr[i], input_arr[i+1]));
    }
    while(!res.empty()){
        cout<<res.top()<<" ";
        res.pop();
    }
    cout<<'\n';
    return 0;
}