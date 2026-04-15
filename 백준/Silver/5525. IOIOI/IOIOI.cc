#include <bits/stdc++.h>

using namespace std;

int n, m;
int res = 0;
string target_string;
string input_string;
vector<int> pi;

void input();
void get_pi();
void kmp();

int main() {
    input();
    get_pi();
    kmp();
    cout << res << '\n';
    return 0;
}

void kmp() {
    int j = 0;
    for (int i = 0; i < input_string.size(); ++i) {
        while (j > 0 && input_string[i] != target_string[j]) {
            j = pi[j - 1];
        }
        if (input_string[i] == target_string[j]) {
            if (j == target_string.size() - 1) {
                res++;
                j = pi[j];
            } else {
                ++j;
            }
        }
    }
}

void get_pi() {
    int j = 0;
    pi.resize(target_string.size());
    for (int i = 1; i < target_string.size(); ++i) {
        while (j > 0 && target_string[i] != target_string[j]) {
            j = pi[j - 1];
        }
        if (target_string[i] == target_string[j]) {
            pi[i] = ++j;
        } else {
            pi[i] = 0;
        }
    }
}

void input() {
    cin >> n >> m;
    cin >> input_string;

    target_string = "I";
    for (int i = 0; i < n; i++) {
        target_string += "OI";
    }
}
