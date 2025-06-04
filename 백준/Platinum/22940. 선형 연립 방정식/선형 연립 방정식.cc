#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
최대 6개의 미지수
미지수의 계수는 10이하의 양수

1. 기준열에 대해서 최소공배수를 도출해준다.
2. 해당 열의 최상위행을 기준으로 아래 행들에 대한 제거작업을 진행해준다
3. 변형행들의 다음 요소가 음수라면 -1을 곱해준다
4. 각 행에 대해 GCD 약분을 통해 수를 줄여준다
*/

ll gcd(ll a, ll b);
ll lcm(ll a, ll b);
void input();
void func();
void output();

ll n;
vector<vector<ll>> arr;
vector<ll> res;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    func();
    output();
    return 0;
}


void func(){
    for(ll i = 0; i < n; i++){
        // i번 행을 기준행으로 삼는다
        ll pivot = i;
        while (pivot < n && arr[pivot][i] == 0) pivot++;
        if (pivot == n) continue;
        if (pivot != i) swap(arr[i], arr[pivot]);

        // 기준행에 대해 아래 행들을 제거해준다
        for(ll j = i + 1; j < n; j++){
            if (arr[j][i] == 0) continue;

            // 두 행의 i번째 계수를 맞추기 위해 최소공배수를 구한다
            ll a = arr[i][i], b = arr[j][i];
            ll L = lcm(abs(a), abs(b));
            ll a_mul = L / abs(a), b_mul = L / abs(b);

            // 부호가 다르면 부호를 반대로 맞춰줌 (빼기 결과가 양수되도록)
            if (a * b < 0) a_mul = -a_mul;

            // 해당 두 행을 계수 맞춰서 소거 연산 수행
            for(ll k = i; k <= n; k++){
                arr[j][k] = arr[j][k] * b_mul - arr[i][k] * a_mul;
            }

            // 소거 후 해당 행 전체를 GCD로 약분하여 수 크기를 줄여준다
            ll row_gcd = 0;
            for(ll k = i; k <= n; k++){
                row_gcd = gcd(row_gcd, abs(arr[j][k]));
            }
            if(row_gcd > 1){
                for(ll k = i; k <= n; k++){
                    arr[j][k] /= row_gcd;
                }
            }

            // i번째 계수가 음수라면 -1을 곱해준다 (양수 유지)
            if(arr[j][i] < 0){
                for(ll k = i; k <= n; k++){
                    arr[j][k] *= -1;
                }
            }
        }
    }

    // 정리작업 완료. 역순으로 돌아가며, 미지수 정리작업 진행
    for(ll i = n - 1; i >= 0; i--){
        for(ll j = n - 1; j > i; j--){
            arr[i][n] -= arr[i][j] * res[j];
            arr[i][j] = 0;
        }
        res[i] = arr[i][n] / arr[i][i];
    }
}

void input(){
    cin >> n;
    res.resize(n);
    arr.resize(n);
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j <= n; j++){
            ll k; cin >> k;
            arr[i].push_back(k);
        }
    }
}

void output(){
    for(ll i = 0; i < n; i++){
        cout << res[i] << ' ';
    }
    cout << '\n';
}

ll gcd(ll a, ll b){
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}