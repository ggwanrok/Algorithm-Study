#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;
int operator_arr[4];

int max_res;
int min_res;

int func_oper(int a, int b, int num){
    if(num == 0) return a+b;
    if(num == 1) return a-b;
    if(num == 2) return a*b;
    return a/b;
}

void func_main(int i, int value){
    if(i == n){
        max_res = max(max_res, value);
        min_res = min(min_res, value);
        return;
    }
    
    for(int iter=0; iter<4; iter++){
        if(operator_arr[iter] != 0){
            operator_arr[iter]--;
            //로직 수행
            func_main(i+1, func_oper(value, arr[i], iter));
            operator_arr[iter]++;
        }
    }
}

int main(){
    max_res = INT_MIN;
    min_res = INT_MAX;
    cin>>n;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        arr.push_back(k);
    }
    for(int i=0; i<4; i++){
        cin>>operator_arr[i];
    }

    //0~n-2까지 내려야 할 것 같음.
    func_main(1,arr[0]);
    cout<<max_res<<'\n'<<min_res<<'\n';
    return 0;
}