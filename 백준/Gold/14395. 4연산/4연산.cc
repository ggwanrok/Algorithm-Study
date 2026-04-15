#include <bits/stdc++.h>
using namespace std;

/*
+ : 2배 이벤트
- : 0이 될 수 있음. (s != 0 && t == 0 일 때 말곤 쓸 일 X)
* : 제곱 이벤트
/ : 1이 됨

-> * or + 로만 진행을 해본다. -> 안된다?
-> 1 부터 진행을 해본다. -> 안된다?
-> -1 출력.
*/

typedef long long ll;
typedef pair<ll, string> pls;

ll s, t;
set<ll> visited;

void input();
void func();

int main(){
    input();
    func();
    return 0;
}

void func() {
    if (s == t) {
        cout << 0 << '\n';
        return;
    }

    if (t == 0) {
        cout<<'-'<<'\n';
        return;
    }
    
    queue<pls> q;
    q.push({s, ""});
    visited.insert(s);
    
    while (!q.empty()) {
        ll cur = q.front().first;
        string op = q.front().second;
        q.pop();
        
        if (cur == t) {
            cout << op << '\n';
            return;
        }
        
        // 곱셈 연산
        if (cur * cur <= t && visited.find(cur * cur) == visited.end()) {
            visited.insert(cur * cur);
            q.push({cur * cur, op + '*'});
        }
        
        // 더하기 연산
        if (cur + cur <= t && visited.find(cur + cur) == visited.end()) {
            visited.insert(cur + cur);
            q.push({cur + cur, op + '+'});
        }
        
        // 나누기 연산 (cur이 1보다 클 때)
        if (cur != 0 && visited.find(1) == visited.end()) {
            visited.insert(1);
            q.push({1, op + '/'});
        }
    }
    
    // 위의 연산들로도 t에 도달하지 못했을 경우
    cout << -1 << '\n';
}

void input(){
    cin>>s>>t;
}
