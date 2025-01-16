#include <bits/stdc++.h>

using namespace std;
#define ll long long

pair<ll, ll> a1;
pair<ll, ll> a2;

pair<ll, ll> b1;
pair<ll, ll> b2;

int ccw(pair<ll, ll>, pair<ll, ll>, pair<ll, ll>);
bool isBetween(pair<ll, ll>, pair<ll, ll>, pair<ll, ll>);

void input();
void func();

int main() {
    input();
    func();
    return 0;
}

bool isBetween(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> r) {
    return min(p1.first, p2.first) <= r.first && r.first <= max(p1.first, p2.first) &&
           min(p1.second, p2.second) <= r.second && r.second <= max(p1.second, p2.second);
}

int ccw(pair<ll, ll> x, pair<ll, ll> y, pair<ll, ll> z) {
    ll r = x.first * y.second + y.first * z.second + z.first * x.second -
           (y.first * x.second + z.first * y.second + x.first * z.second);
    if (r > 0) return 1;    // 반시계 방향
    else if (r == 0) return 0; // 일직선
    else return -1;         // 시계 방향
}

void func() {
    int ccw1_1 = ccw(a1, a2, b1);
    int ccw1_2 = ccw(a1, a2, b2);
    int res1 = ccw1_1 * ccw1_2;

    int ccw2_1 = ccw(b1, b2, a1);
    int ccw2_2 = ccw(b1, b2, a2);
    int res2 = ccw2_1 * ccw2_2;

    if (res1 <= 0 && res2 <= 0) { // 교차 가능성이 있는 경우
        if (res1 == 0 && res2 == 0) { // 일직선인 경우
            if (isBetween(a1, a2, b1) || isBetween(a1, a2, b2) || isBetween(b1, b2, a1) || isBetween(b1, b2, a2)) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else { // 일반 교차
            cout << 1 << '\n';
        }
    } else {
        cout << 0 << '\n';
    }
}

void input() {
    ll v1, v2, v3, v4, v5, v6, v7, v8;
    cin >> v1 >> v2 >> v3 >> v4 >> v5 >> v6 >> v7 >> v8;
    a1 = {v1, v2};
    a2 = {v3, v4};
    b1 = {v5, v6};
    b2 = {v7, v8};
}
