#include <bits/stdc++.h>

using namespace std;

// 문자열 길이 최대 10.
// 알파벳 소문자로만 구성됨.
// 1인 녀석들 : 어디 두던지 상관 없음.

vector<int> alpha_list; // 각 알파벳의 빈도 수를 저장
int list_size; // 알파벳 종류의 수
int full_size; // 구성되어야 하는 문자열의 길이
int res = 0; // 유효한 문자열 수를 저장

void input();
void func();
void bk_tracking(int, int); // 직전에 들어간 인덱스 위치, 진행 위치

int main(void) {
    input();
    func();
    cout << res << '\n';
    return 0;
}

// 백트래킹 함수
void bk_tracking(int pre, int cur) {
    if (cur == full_size) {
        res++;
        return;
    }

    for (int i = 0; i < list_size; i++) {
        if (alpha_list[i] > 0 && pre != i) {
            alpha_list[i]--;
            bk_tracking(i, cur + 1);
            alpha_list[i]++;
        }
    }
}

void func() {
    bk_tracking(-1, 0); // 초기에는 어떤 문자도 배치되지 않았으므로 -1 사용
}

void input() {
    string s;
    cin >> s;
    full_size = s.length();
    vector<int> input_string(26, 0);
    for (char c : s) {
        input_string[c - 'a']++;
    }
    for (int i = 0; i < input_string.size(); i++) {
        if (input_string[i] > 0) {
            alpha_list.push_back(input_string[i]);
        }
    }
    list_size = alpha_list.size();
}
