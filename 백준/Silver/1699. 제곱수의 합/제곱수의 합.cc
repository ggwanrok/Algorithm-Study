#include <bits/stdc++.h>

using namespace std;


int n;
vector<int> sq;
int arr[100001];

void input();
void func();
void output();

int main(){
    input();
    func();
    output();
    return 0;
}

void func(){
    int k = 0;
    while(sq[k] <= n){
        for(int i=1; i<=n; i++){
            if(i < sq[k]) continue;
            arr[i] = min(arr[i], arr[i-sq[k]]+1);
        }
        k++;
    }
}

void output(){
    cout<<arr[n]<<'\n';

}
void input(){
    cin>>n;
    int i = 1;
    while(i * i <= 100000){
        sq.push_back(i*i);
        i++;
    }
    memset(arr, 1000000, sizeof(arr));
    for(int i=0; i<sq.size(); i++){
        arr[sq[i]] = 1;
    }
}