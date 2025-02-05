#include <bits/stdc++.h>

using namespace std;

int n;
int ex_n;
vector<int> v;

/*
0일 때 0명
1일 때 양쪽 한명 제외
2일 때 양쪽 한명 제외
3일 때 양쪽 한명 제외
.
.
7일 때 양쪽 두명 제외


*/

void input(){
    cin>>n;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
}

int round_div(int a, int b) {
    /*
    소수에 대한 평가는 반올림...
    정수에 대한 연산은 애초에 내림.
    0.5씩 더해서 처리하자.
    */
    return (a + (b / 2)) / b;
}

void func() {
    int ex_n = round_div(n * 15, 100);  
    
    // 모든 요소가 제외되는 경우 방지
    if (ex_n * 2 >= n) {
        cout << "0"<<'\n';
        return;
    }

    int res = 0;
    for (int i = ex_n; i < n - ex_n; i++) {
        res += v[i];
    }
    
    res = round_div(res, n - 2 * ex_n);
    cout << res << '\n';
}

int main(){
    input();
    func();
    return 0;
}