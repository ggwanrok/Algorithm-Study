#include <bits/stdc++.h>
using namespace std;

/*
30의 배수 -> 끝자리 0 하나 확보.
그 뒤에 3의 배수 조건 확인
-> 3의 배수 조건이란,
각 자리수의 합이 3의 배수이면 됨.
따라서 합이 3의 배수라면 그냥 내림차순으로 풀이
*/

vector<int> v;

bool compare(int a, int b){
    return a>b;
}

int main(){
    string s;
    cin>>s;
    for(int i=0; i<s.length(); i++){
        v.push_back(s[i]-'0');
    }
    sort(v.begin(), v.end(), compare);
    
    if(v[v.size()-1] != 0){
        cout<<-1;
    }
    else{
        int sum = 0;
        for(int i=0; i<v.size()-1; i++){
            sum += v[i];
        }
        if(sum%3 == 0){
            for(int cur : v){
                cout<<cur;
            }
        }
        else{
            cout<<-1;
        }
    }
    cout<<'\n';
    return 0;
}