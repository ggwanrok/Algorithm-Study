#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<long long, long long>> points;

void input();
void func();
void output();
double polygon_area(const vector<pair<long long, long long>>& points);

int main() {
    input();
    func();
    return 0;
}

void input() {
    cin >> n;
    points.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
}

double polygon_area(const vector<pair<long long, long long>>& points) {
    long long area = 0;
    int n = points.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;  // 다음 점의 인덱스 (마지막 점의 경우 첫 점과 연결)
        area += points[i].first * points[j].second;
        area -= points[i].second * points[j].first;
    }
    return abs(area) / 2.0;
}

void func() {
    double area = polygon_area(points);
    cout << fixed << setprecision(1) << area << '\n';
}
