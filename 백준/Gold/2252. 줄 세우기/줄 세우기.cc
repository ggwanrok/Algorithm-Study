#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> res;
vector<vector<int>> pre_to_post;
vector<int> pre_person;

void input();
void func(); //그냥 위상정렬 쓰면 될듯?
void output();

int main(){
    input();
    func();
    output();
    return 0;
}

void func(){
    //반복을 통해서 큐에 앞에 더이상 필요한게 없는 녀석들을 push해준다.
    //이들은 그 자리에 서도 된다는 뜻이므로 결과에 넣어준다.
    //큐에 들어있는 녀석들을 다른 녀석들 앞에 세워도 되는지 찾아본다.
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(pre_person[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int idx = q.front();
        res.push_back(idx);
        q.pop();
        for(int post : pre_to_post[idx]){
            if(pre_person[post] > 0) pre_person[post]--;
            if(pre_person[post] == 0) q.push(post);
        }
    }
}

void input(){
    cin>>n>>m;
    pre_to_post.resize(n+1);
    pre_person.resize(n+1, 0);
    for(int i=0; i<m; i++){
        int pre, post;
        cin>>pre>>post;
        pre_to_post[pre].push_back(post);
        pre_person[post]++;
    }
}

void output(){
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
}