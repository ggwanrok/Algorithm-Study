#include <bits/stdc++.h>

using namespace std;

int n;
stack<int> s;
vector<int> target;
stack<int> origin;
vector<char> res;

int main() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        target.push_back(c);
    }
    
    for (int i = n; i > 0; i--) {
        origin.push(i);
    }

    int i = 0; // target의 현재 인덱스
    while (i < target.size()) {
        // origin에서 숫자를 꺼내서 스택에 넣음
        while (!origin.empty() && (s.empty() || s.top() < target[i])) {
            s.push(origin.top());
            origin.pop();
            res.push_back('+');
        }
        
        // 스택의 top과 target을 비교
        if (!s.empty() && s.top() == target[i]) {
            s.pop();
            res.push_back('-');
            i++;
        } else {
            // 더 이상 진행할 수 없으면 NO 출력
            cout << "NO" << '\n';
            return 0;
        }
    }
    
    // 결과 출력
    for (char c : res) {
        cout << c << '\n';
    }
    
    return 0;
}
