#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    stack<char> st;
    long long total = 0; // 최종 결과값
    int temp = 1;        // 현재 괄호 깊이에 따른 배수
    bool is_impossible = false;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            temp *= 2;
            st.push('(');
        } 
        else if (s[i] == '[') {
            temp *= 3;
            st.push('[');
        } 
        else if (s[i] == ')') {
            // 잘못된 경우: 스택이 비어있거나 짝이 안 맞음
            if (st.empty() || st.top() != '(') {
                is_impossible = true;
                break;
            }
            // 바로 직전이 열린 괄호였다면 (= 가장 안쪽 괄호 쌍 완성)
            if (s[i - 1] == '(') {
                total += temp;
            }
            st.pop();
            temp /= 2; // 껍데기를 하나 벗었으므로 다시 /2
        } 
        else if (s[i] == ']') {
            // 잘못된 경우: 스택이 비어있거나 짝이 안 맞음
            if (st.empty() || st.top() != '[') {
                is_impossible = true;
                break;
            }
            // 바로 직전이 열린 괄호였다면
            if (s[i - 1] == '[') {
                total += temp;
            }
            st.pop();
            temp /= 3; // 껍데기를 하나 벗었으므로 다시 /3
        }
    }

    // 모든 과정을 마친 후 스택이 남아있어도 잘못된 괄호임
    if (is_impossible || !st.empty()) {
        cout << 0 << "\n";
    } else {
        cout << total << "\n";
    }

    return 0;
}