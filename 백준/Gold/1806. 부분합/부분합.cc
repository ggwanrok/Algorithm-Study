#include <bits/stdc++.h>

using namespace std;

int n, s;
int res = 100001;
vector<int> v;
vector<int> v_sum;

void input();
void func();
void output();

int main(void){
    input();
    func();
    output();
    return 0;
}

void func(){
    int p1=0, p2=-1;

    for(int i=0; i<n; i++){
        if(v_sum[i] >= s){
            p2 = i;
            break;
        }
    }
    if(p2 == -1){
        cout<<0<<'\n';
        exit(0);
    }
    //현 시점은 0번인덱스부터 p2까지의 합이 s이상이 되는 초기 지점이다.
    //p1을 옮겨올 수 있으면 옮긴다.
    //옮길 수 없다면, p2인덱스 자리값이 끝일 때의 최대 갯수이다.
    //갯수를 저장한 뒤, p2를 1 늘려서 같은 작업을 해준다.
    while(p2 < n){
        if(v_sum[p2] - v_sum[p1] >= s){
            p1++;
        }
        else{
            int answer = p2-p1+1;
            if(answer < res){
                res = answer;
            }
            p2++;
        }
    }
}

void input(){
    cin>>n>>s;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        v.push_back(k);
    }
    v_sum.resize(n);
    v_sum[0] = v[0];
    for(int i=1; i<n; i++){
        v_sum[i] += v[i] + v_sum[i-1];
    }
}

void output(){
    cout<<res<<'\n';
}