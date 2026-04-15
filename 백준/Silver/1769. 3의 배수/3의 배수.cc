#include <bits/stdc++.h>
using namespace std;

string digit_sum(string num_str) {
    int sum = 0;
    for (char c : num_str) {
        sum += c - '0';
    }
    return to_string(sum);
}

int main() {
    string x;
    int cnt = 0;
    cin >> x;

    while (x.size() > 1) {
        x = digit_sum(x);
        cnt++;
    }

    cout << cnt << '\n';
    if ((x[0] - '0') % 3 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}