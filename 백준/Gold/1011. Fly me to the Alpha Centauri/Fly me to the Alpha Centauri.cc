#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        long long x, y;
        cin >> x >> y;

        long long dist = y - x;
        if (dist == 0) {
            cout << 0 << '\n';
            continue;
        }

        long long moves = 0;
        long long covered = 0;
        long long step = 1;

        //걸음걸이마다 도달할 수 있는 최대거리가 존재.
        //해당 최대거리 이내에 대해서는 해당 보폭으로 해결할 수 있다. (일정한 증감비율로 인해서)
        //그래서 결과적으로 피라미드식 그래프 형태를 보이는 구조이기 때문에
        //홀수일 때 탑을 올리고, 짝수일 때 같은 높이를 한번 더 올리는 것까지 가능하고 해당 범위까지 커버가 가능해진다.
        //커버 가능한 범위 내의 거리가 산정되면 해당 값이 최솟값이다.
        while (covered < dist) {
            covered += step;
            moves++;
            if (covered >= dist) break;

            covered += step;
            moves++;
            if (covered >= dist) break;

            step++;
        }

        cout << moves << '\n';
    }

    return 0;
}
