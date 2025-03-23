#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

int n, k;
vector<bool> is_prime;
vector<bool> has_prime_divisor;

void input(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    is_prime.resize(MAX + 1, true);
    has_prime_divisor.resize(MAX + 1, false);

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }

    cin >> n >> k;

    // k보다 큰 소수의 배수들을 마킹
    for (int p = k + 1; p <= n; ++p) {
        if (!is_prime[p]) continue;
        for (int multiple = p; multiple <= n; multiple += p) {
            has_prime_divisor[multiple] = true;
        }
    }
}

void func(){
    int res = 0;
    for (int val = n; val > 0; val--) {
        if (!has_prime_divisor[val]) {
            res++;
        }
    }
    cout << res << '\n';
}

int main() {
    input();
    func();
    return 0;
}
