#include <iostream>
#define ll long long
using namespace std;

ll eulerPhi(ll n) {
    ll result = n;
    for (ll p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main() {
    ll n;
    cin >> n;
    cout << eulerPhi(n) << '\n';
    return 0;
}
