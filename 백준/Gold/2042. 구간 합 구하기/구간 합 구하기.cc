#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> tree;
vector<ll> arr;
int n, m, k;

ll init(int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

ll query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, ll diff) {
    if (idx < start || idx > end) return;
    tree[node] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, diff);
        update(node * 2 + 1, mid + 1, end, idx, diff);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    
    arr.resize(n + 1);
    tree.resize(4 * n);
    
    for (int i = 1; i <= n; i++) cin >> arr[i];
    init(1, 1, n);
    
    int total = m + k;
    while (total--) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) { 
            ll diff = c - arr[b];
            arr[b] = c;
            update(1, 1, n, b, diff);
        } else { 
            cout << query(1, 1, n, b, c) << '\n';
        }
    }
}
