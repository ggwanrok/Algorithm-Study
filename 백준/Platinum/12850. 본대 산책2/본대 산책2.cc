#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;



vector<vector<ll>> soongsil;


vector<vector<ll>> multiply(vector<vector<ll>>& A, vector<vector<ll>>& B);
ll power(vector<vector<ll>> A, int n);

int main(){

    int d; cin>>d;

    soongsil.resize(8);
    for(int i=0; i<8; i++){
        soongsil[i].resize(8, 0);
    }

    soongsil[0][1] = soongsil[0][2] = 1;
    soongsil[1][0] = soongsil[1][2] = soongsil[1][3] = 1;
    soongsil[2][0] = soongsil[2][1] = soongsil[2][3] = soongsil[2][4] = 1;
    soongsil[3][1] = soongsil[3][2] = soongsil[3][4] = soongsil[3][5] = 1;
    soongsil[4][2] = soongsil[4][3] = soongsil[4][5] = soongsil[4][7] = 1;
    soongsil[5][3] = soongsil[5][4] = soongsil[5][6] = 1;
    soongsil[6][5] = soongsil[6][7] = 1;
    soongsil[7][4] = soongsil[7][6] = 1;

    cout<<power(soongsil, d)<<'\n';

    return 0;
}


vector<vector<ll>> multiply(vector<vector<ll>>& A, vector<vector<ll>>& B) {
    vector<vector<ll>> C(8, vector<ll>(8, 0));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

ll power(vector<vector<ll>> A, int n) {
    vector<vector<ll>> res(8, vector<ll>(8, 0));
    for (int i = 0; i < 8; i++) res[i][i] = 1; // 단위 행렬

    while (n > 0) {
        if (n % 2 == 1) res = multiply(res, A);
        A = multiply(A, A);
        n /= 2;
    }
    

    return res[0][0];
}

