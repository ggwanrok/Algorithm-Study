#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;
int res = 0;

void input();
void func();
int lis(vector<int>&, int, int);
void output();

int main() {
    input();
    func();
    output();
    return 0;
}

int lis(vector<int>& seq, int start, int end) {
    vector<int> lis;
    for (int i = start; i <= end; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), seq[i]);
        if (it == lis.end()) {
            lis.push_back(seq[i]);
        } else {
            *it = seq[i];
        }
    }
    return lis.size();
}

void func() {
    vector<int> lis_inc_len(n), lis_dec_len(n);

    for (int k = 0; k < n; k++) {
        lis_inc_len[k] = lis(arr, 0, k); // 증가 수열의 길이
    }

    for (int k = 0; k < n; k++) {
        vector<int> rev(arr.begin() + k, arr.end());  // arr의 부분을 뒤집기 위해 벡터 슬라이싱
        reverse(rev.begin(), rev.end());
        lis_dec_len[k] = lis(rev, 0, rev.size() - 1); // 감소 수열의 길이
    }

    for (int k = 0; k < n; k++) {
        res = max(res, lis_inc_len[k] + lis_dec_len[k] - 1);
    }
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        arr.push_back(k);
    }
}

void output() {
    cout << res << '\n';
}
