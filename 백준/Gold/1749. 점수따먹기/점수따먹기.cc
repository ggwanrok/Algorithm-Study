#include <bits/stdc++.h>
using namespace std;

int arr[201][201];
int temp[201];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> arr[i][j];

    int res = INT_MIN;
    //부분합스러운 문제.
    //정해진 폭에 대해서, 일차원 배열에 저장해서 작업해주기.
    for(int top = 0; top < n; top++){
        memset(temp, 0, sizeof(temp));
        for(int bot = top; bot < n; bot++){
            for(int i=0; i<m; i++)
                temp[i] += arr[bot][i];
            //temp 배열에 현 시점작업할 두께에 대해서 합산 정보가 저장됨.
            //이 구조 속에서 누적합의 최대를 고려하면 됨.
            int sum = 0;
            int cur_res = INT_MIN;
            for(int i=0; i<m; i++){
                sum = max(temp[i], sum+temp[i]);
                cur_res = max(cur_res, sum);
            }
            res = max(res, cur_res);
        }
    }
    cout<<res<<'\n';
    return 0;
}
