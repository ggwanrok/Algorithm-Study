#include <bits/stdc++.h>
using namespace std;

int l, c;
vector<char> v;
vector<string> res;

bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void dfs(string s, int idx) {
    if (s.length() == l) {
        int vowel = 0, consonant = 0;
        for (char ch : s) {
            if (isVowel(ch)) vowel++;
            else consonant++;
        }
        if (vowel >= 1 && consonant >= 2)
            res.push_back(s);
        return;
    }

    for (int i = idx; i < c; i++) {
        dfs(s + v[i], i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> l >> c;
    v.resize(c);
    for (int i = 0; i < c; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    dfs("", 0);

    for (string s : res) {
        cout << s << "\n";
    }

    return 0;
}