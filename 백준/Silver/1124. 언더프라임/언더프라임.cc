#include <bits/stdc++.h>
using namespace std;

int a, b;
int res;
bool is_prime[100001]; // 소수인지 판별하는 배열
vector<int> prime_group;

void input();
void func();
void output();
int get_prime_count(int);
void get_prime();

int main(void){
    input();
    func();
    output();
    return 0;
}

void input(){
    cin >> a >> b;
    fill(is_prime, is_prime + 100001, true);
    is_prime[0] = is_prime[1] = false; // 0과 1은 소수가 아님
    get_prime();
}

void get_prime(){
    for (int i = 2; i <= 100000; ++i) {
        if (is_prime[i]) {
            for (int j = i + i; j <= 100000; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= 100000; ++i) {
        if (is_prime[i]) {
            prime_group.push_back(i);
        }
    }
}

int get_prime_count(int x){
    int count = 0;
    for (int i = 0; i < prime_group.size() && prime_group[i] * prime_group[i] <= x; ++i) {
        while (x % prime_group[i] == 0) {
            x /= prime_group[i];
            ++count;
        }
    }
    if (x > 1) ++count; // 남아있는 소인수 처리
    return count;
}

void func(){
    for (int i = a; i <= b; ++i) {
        int prime_factors_count = get_prime_count(i);
        if (is_prime[prime_factors_count]) {
            ++res;
        }
    }
}

void output(){
    cout << res << '\n';
}
