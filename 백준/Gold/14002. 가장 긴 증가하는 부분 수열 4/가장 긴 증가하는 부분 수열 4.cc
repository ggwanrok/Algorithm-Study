#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1001];
int pre[1001];
vector<int> dp;
vector<int> dp_idx;
stack<int> s;

void input();
void func();
void output();

int main() {
    input();
    func();
    output();

    return 0;
}

void func() {
    //길이를 구하는 것에는 문제가 없다.
    //아 인덱스를 넣어줘.
    
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
        int j = it - dp.begin();
        if(it == dp.end()){
            dp.push_back(arr[i]);
            dp_idx.push_back(i);
        }
        else{
            dp[j] = arr[i];
            dp_idx[j] = i;
        }
        if(j != 0){
            pre[i] = dp_idx[j-1];
        }
    }
    int idx = dp_idx.back();
    while(idx != -1){
        s.push(arr[idx]);
        idx = pre[idx];
    }
    
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pre[i] = -1;
    }
}

void output() {
    cout << dp.size() << '\n';
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout << '\n';
}
