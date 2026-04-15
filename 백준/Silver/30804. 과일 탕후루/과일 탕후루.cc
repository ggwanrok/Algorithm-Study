#include <bits/stdc++.h>
using namespace std;

int n;
int isIn[10]; // 과일 번호는 0~9로 제한
int inCnt;    // 현재 윈도우에 포함된 과일 종류의 개수
int ans;
int p1, p2;
vector<int> f;

int main() {
    cin >> n;
    f.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    if (n < 2) {
        cout << n << '\n';
        return 0;
    }

    p1 = 0; p2 = 0; inCnt = 0; ans = 0;
    while (p2 < n) {
        if (isIn[f[p2]] == 0) {
            inCnt++; // 새로운 과일 종류 추가
        }
        isIn[f[p2]]++;
        p2++;

        // 과일 종류가 2개를 초과하면 p1을 이동시켜 슬라이딩 윈도우를 축소
        while (inCnt > 2) {
            isIn[f[p1]]--;
            if (isIn[f[p1]] == 0) {
                inCnt--; // 과일 종류 감소
            }
            p1++;
        }

        // 현재 슬라이딩 윈도우의 길이를 갱신
        ans = max(ans, p2 - p1);
    }

    cout << ans << '\n';
    return 0;
}
