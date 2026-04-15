#include <iostream>
using namespace std;
typedef long long ll;

/*
점화식이 이렇다길래 어찌저찌 억지로 풀어둔 문제. 점화식은 아직도 이해 안감.
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N, K;
    cin >> N >> K;

    ll ans = 0; //마지막으로 배제된 사람 번호
    ll NN = 1; //현재까지 고려한 인원들들
    if (K == 1) {
        cout << N;
    } else {
        while (true) {
            ll x = (NN - ans - 1) / (K - 1) + 1; //표본집단 내부적으로 배제할 수 있는 최대 인원
            if (NN + x > N) { //더 제거할 수 없다면,
                ans += (N - NN) * K; //마지막까지 배제를 진행하여 ans 값에 접근
                ans %= N;
                break;
            }
            NN += x; //고려한 인원들에 추가
            ans = (ans + K * x) % (NN); //해당 NN에서 x만큼 추가로 고려했을 때, 처리한 뒤 ans 상태.
            
        }
        cout << ans + 1;
    }
}
