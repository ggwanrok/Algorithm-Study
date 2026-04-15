#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll res;
ll arr[4001][4];

vector<ll> AB;
vector<ll> CD;

void input();
void func();
void output();

int main(){
    input();
    func();
    output();
    return 0;
}
void func() {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            AB.push_back(arr[i][0] + arr[j][1]);
            CD.push_back(arr[i][2] + arr[j][3]);
        }
    }
    sort(AB.begin(),AB.end());
    sort(CD.begin(), CD.end());

    for(int i=0; i<AB.size(); i++){

        //AB 배열의 음수부분 이상이 되는 최초의 인덱스
        int b_lower_bound = lower_bound(CD.begin(),CD.end(), -AB[i]) -CD.begin();
        //AB 배열의 음수부분 초과가 되는 최도의 인덱스
        int b_upper_bound = upper_bound(CD.begin(),CD.end(), -AB[i]) -CD.begin();

        //해당 값으로 접근을 할 떄,
        //둘이 +-만 다른 값을 구해야하는 구조.
        //원하는 값 초과 최초 인덱스 - 원하는 값 이상 최초 인덱스 => 같은 값의 갯수.
        res += b_upper_bound - b_lower_bound;
    }
}


void input(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<4; j++){
            cin>>arr[i][j];
        }
    }
}

void output(){
    cout<<res<<'\n';
}
