#include <bits/stdc++.h>
using namespace std;

int a_cnt[26]; // 대문자 A-Z의 개수를 저장
vector<char> lef; // 왼쪽 절반
char mid = '\0';  // 홀수 개수인 문자 (중앙)

int main() {
    string s;
    cin >> s;

    // 알파벳 개수 세기
    for (char c : s) {
        a_cnt[c - 'A']++;
    }

    // 홀수 개수 확인 및 중앙 문자 처리
    for (int i = 0; i < 26; i++) {
        if (a_cnt[i] % 2 != 0) {
            if (mid != '\0') { // 이미 홀수 개수가 하나 있다면 팰린드롬 불가능
                cout << "I'm Sorry Hansoo\n";
                return 0;
            }
            mid = i + 'A'; // 중앙 문자는 홀수인 문자
        }
        a_cnt[i] /= 2; // 왼쪽 절반에 넣을 문자 개수
    }

    // 왼쪽 절반 구성
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < a_cnt[i]; j++) {
            lef.push_back(i + 'A');
        }
    }

    sort(lef.begin(), lef.end());

    // 팰린드롬 출력
    for (char c : lef) {
        cout << c;
    }
    if (mid != '\0') {
        cout << mid;
    }
    for(int i=lef.size()-1; i>=0; i--){
        cout<<lef[i];
    }
    cout << '\n';

    return 0;
}
