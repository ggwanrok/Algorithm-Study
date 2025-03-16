#include <bits/stdc++.h>

using namespace std;

int n;
int base;
int res;
vector<int> arr;

void input(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    res = 0;
    cin>>n;
    while(n--){
        int k; cin>>k;
        arr.push_back(k);
    }
}

void func(){
    priority_queue<int> pq;
    base = arr[0];
    for(int i=1; i<arr.size(); i++){
        pq.push(arr[i]);
    }
    while(!pq.empty()){
        int cur_top = pq.top();
        pq.pop();
        if(base <= cur_top){
            base++;
            res++;
            cur_top--;
            pq.push(cur_top);
        }
        else{
            break;
        }
    }
}

void output(){
    cout<<res<<'\n';
}

int main(){
    input();
    func();
    output();
    return 0;
}
