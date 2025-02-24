#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int n;
int sum;
int res1;
int res2;
int res3;
int res4;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first > b.first;  // 빈도수 기준 내림차순
    return a.second < b.second;  // 값 기준 오름차순
}

void input() {
    cin >> n;
    sum = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        v.push_back(k);
        sum += k;
    }
}

void func() {
    sort(v.begin(), v.end());

    res1 = round((double)sum / n);  // 산술평균

    res2 = v[n / 2];  // 중앙값

    vector<pair<int, int>> v3;
    int cnt = 1;

    for (int i = 1; i < n; i++) {
        if (v[i] == v[i - 1]) {
            cnt++;
        } else {
            v3.push_back({cnt, v[i - 1]});
            cnt = 1;
        }
    }
    v3.push_back({cnt, v[n - 1]});  // 마지막 요소 추가

    sort(v3.begin(), v3.end(), compare);

    if (v3.size() == 1 || v3[0].first != v3[1].first) {
        res3 = v3[0].second;  // 최빈값 하나
    } else {
        res3 = v3[1].second;  // 두 번째로 작은 값
    }

    res4 = v.back() - v.front();  // 범위

    cout << res1 << '\n' << res2 << '\n' << res3 << '\n' << res4 << '\n';
}

int main() {
    input();
    func();
    return 0;
}
