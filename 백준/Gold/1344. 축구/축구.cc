#include <bits/stdc++.h>

using namespace std;

double a, b;
double na, nb;

double a_arr[19]; 
double b_arr[19];
int is_prime[19];

void input() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b;

    a /= 100.0;
    b /= 100.0;
    na = 1 - a;
    nb = 1 - b;

    memset(is_prime, 0, sizeof(is_prime));
    is_prime[2] = 1; is_prime[3] = 1; is_prime[5] = 1;
    is_prime[7] = 1; is_prime[11] = 1; is_prime[13] = 1;
    is_prime[17] = 1;
}

void func() {
    fill(a_arr, a_arr + 19, 0.0);
    fill(b_arr, b_arr + 19, 0.0);
    
    a_arr[0] = 1.0;
    b_arr[0] = 1.0;

    for (int i = 1; i <= 18; i++) {
        for (int j = i; j >= 1; j--) {
            a_arr[j] = a_arr[j] * na + a_arr[j - 1] * a;
        }
        a_arr[0] *= na;
    }

    for (int i = 1; i <= 18; i++) {
        for (int j = i; j >= 1; j--) {
            b_arr[j] = b_arr[j] * nb + b_arr[j - 1] * b;
        }
        b_arr[0] *= nb;
    }


    double neither_prime_prob = 0;
    for (int i = 0; i <= 18; i++) {
        for (int j = 0; j <= 18; j++) {
            double prob = a_arr[i] * b_arr[j];
            if (is_prime[i] == 0 && is_prime[j] == 0) {
                neither_prime_prob += prob;
            } 
        }
    }

    cout << fixed << setprecision(10) << 1 - neither_prime_prob << '\n';
}

int main() {
    input();
    func();
    return 0;
}
