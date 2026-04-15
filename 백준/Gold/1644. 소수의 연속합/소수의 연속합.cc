#include <bits/stdc++.h>

using namespace std;

int n;
int res=0;
vector<int> prime_num; //n 이하의 소수 모임. 이걸 가지고 슬라이딩 윈도우를 써먹어보자.
int num_arr[4000001];

void input();
void get_prime();
void func();
void output();

int main(){
    input();
    func();
    output();
    return 0;
}

void func(){
    int start=0, end=0;
    int sum=0;
    while(end<=prime_num.size()){
        if(sum > n){
            sum -= prime_num[start];
            start++;
        }
        else if(sum < n){
            if(end < prime_num.size()){
                sum += prime_num[end];
            }
            end++;
        }
        else{
            if(end < prime_num.size()){
                sum += prime_num[end];
            }
            end++;
            res++;
        }
    }
}

void input(){
    cin>>n;
    if(n<2){
        cout<<0<<'\n';
        exit(0);
    }
    get_prime();
}

void get_prime(){
    for(int i=2; i<=n; i++){
        num_arr[i] = 1;
    }
    for(int i=2; i*i<=n; i++){
        if(num_arr[i] != 0){
            for(int j=i*i; j<=n; j+=i){
                num_arr[j] = 0;
            }
        }
    }
    for(int i=2; i<=n; i++){
        if(num_arr[i] != 0){
            prime_num.push_back(i);
        }
    }
}

void output(){
    cout<<res<<'\n';
}