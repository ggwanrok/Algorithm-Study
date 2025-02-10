#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

string str;
int n;
vector<string> words;
vector<int> dp;

void input();
void func();
int swap_cnt(string, string);
void output();

int main() {
    input();
    func();
    output();
    return 0;
}

void func() {
    dp[0] = 0;
    
    for (int i = 0; i < str.length(); i++) {
        if (dp[i] == INF) continue; // dp[i]가 INF이면 이미 불가능한 경우
        
        for (int j = 0; j < n; j++) {
            int len = words[j].length();
            if (i + len <= str.length()) {
                int cnt = swap_cnt(str.substr(i, len), words[j]);
                if (cnt != INF) {
                    dp[i + len] = min(dp[i + len], dp[i] + cnt);
                }
            }
        }
    }
}

int swap_cnt(string a, string b) {
    int cnt = 0;
    if (a.size() != b.size()) return INF; // 길이가 다르면 변환 불가
    
    for(int i = 0; i < b.size(); i++) {
        if (a[i] != b[i]) cnt++;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(a != b){
        return INF;
    }

    return cnt;
}

void input() {
    cin >> str;
    cin >> n;
    words.resize(n);
    dp.resize(str.length() + 1, INF);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
}

void output() {
    if (dp[str.length()] == INF) cout << -1 << '\n'; // 변환 불가능하면 -1 출력
    else cout << dp[str.length()] << '\n';
}
