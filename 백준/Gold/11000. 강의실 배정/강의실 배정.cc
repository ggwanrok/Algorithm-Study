#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> lectures;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int start, end;
        cin >> start >> end;
        lectures.push_back({start, end});
    }

    sort(lectures.begin(), lectures.end());

    priority_queue<int, vector<int>, greater<>> pq;

    for (auto [start, end] : lectures) {
        if (!pq.empty() && pq.top() <= start) {
            pq.pop();
        }
        pq.push(end);
    }

    cout << pq.size() << '\n';
    return 0;
}