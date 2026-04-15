#include <bits/stdc++.h>

using namespace std;

int tc;

void input();
void func();
string get_code(int, int);

int do_d(int);
int do_s(int);
int do_l(int);
int do_r(int);

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    input();
    func();
    return 0;
}

string get_code(int value, int target){
    queue<pair<int, string>> q;
    vector<int> is_visited(10000, 0);
    is_visited[value] = 1;
    q.push({value, ""});
    while(!q.empty()){
        int val = q.front().first;
        string str = q.front().second;
        q.pop();
        
        if(val == target){
            return str;
        }
        if(!is_visited[do_d(val)]) {
            q.push({do_d(val), str+'D'});
            is_visited[do_d(val)] = 1;
        }
        if(!is_visited[do_s(val)]) {
            q.push({do_s(val), str+'S'});
            is_visited[do_s(val)] = 1;
        }
        if(!is_visited[do_l(val)]) {
            q.push({do_l(val), str+'L'});
            is_visited[do_l(val)] = 1;
        }
        if(!is_visited[do_r(val)]) {
            q.push({do_r(val), str+'R'}); 
            is_visited[do_r(val)] = 1;
        }  
    }
}



void func(){
    while(tc--){
        int value, target;
        cin>>value>>target;
        cout<<get_code(value, target)<<'\n';
    }
}



int do_d(int x){
    return (x*2) % 10000;
}
int do_s(int x){
    return (x+9999) % 10000;
}
int do_l(int x){
    int k = x / 1000;
    return (x*10) % 10000 + k;
}
int do_r(int x){
    int k = x % 10;
    return x/10 + k*1000;
}

void input(){
    cin>>tc;
}