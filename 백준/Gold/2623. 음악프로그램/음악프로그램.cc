#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> post_singer[1005];
int pre_singer[1005];
vector<int> res;
void input();
void func();
void output();

int main(){
    input();
    func();
    output();
    return 0;
}

void func(){
    queue<int> q;
    //우선도 낮은 녀석들 먼저 넣어주기.
    //앞선 녀석들이 없는 녀석들만이 큐에 담긴다.
    for(int i=1; i<=n; i++){
        if(!pre_singer[i]){
            q.push(i);
        }
    }

    //위상정렬
    /*
    앞선 녀석들에 종속된 녀석들을 pre_singer에서 -1씩 해주면서, 제약을 풀어준다.
    모든 제약이 사라진 녀석은 큐에 담기게 된다.

    불가능한 경우도 있을 수 있다고 하였는데, 그렇게 된다면, 결국 큐는 언젠가 비게 될 것이고,
    제약을 모두 풀지 못한 녀석은 결국 res 에 담기지 못할 것.
    */
    while(!q.empty()){
        int head = q.front();
        q.pop();
        res.push_back(head);

        for(int i=0; i<post_singer[head].size(); i++){
            pre_singer[post_singer[head][i]]--;
            if(!pre_singer[post_singer[head][i]]) q.push(post_singer[head][i]);
        }        
    }
}

void input(){
    cin>>n>>m;
    /*
    m번의 입력을 반복해서 받는다.
    해당 라인에 대한 입력을 받은 뒤,
    2중 for문을 이용하여, 후순위 녀석을 모든 앞순위 녀석에 넣어주도록 한다.
    해당 라인업에서, j란 앞에 몇녀석이 더 있는지를 뜻하기도 해서, pre_singer[singer] 에 j를 더해준다면,
    몇명이 더 필요한지를 알 수 있게 한다.
    */
    for(int i=0; i<m; i++){
        int k; cin>>k;
        vector<int> k_line;
        for(int j=0; j<k; j++){
            int singer;
            cin>>singer;
            pre_singer[singer] += j;
            k_line.push_back(singer);
            for(int s=0; s<j; s++){
                post_singer[k_line[s]].push_back(singer);
            }
        }
    }
}

void output(){
    //res에 n만큼 담기지 못했다는 것은 결국 불가능한 경우가 있다는 뜻.
    if(res.size() != n) {
        cout<<0<<'\n';
        return;
    }
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<'\n';
    }
}