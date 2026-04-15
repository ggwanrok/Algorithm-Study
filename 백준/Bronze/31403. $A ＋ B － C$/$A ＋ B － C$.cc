#include <bits/stdc++.h>

using namespace std;

int main(){
    string a, b;
    int c;
    cin>>a>>b>>c;
    int num_a=0, num_b=0;
    for(int i=0; i<a.length(); i++){
        num_a = num_a * 10 + a[i] - '0';
    }
    for(int i=0; i<b.length(); i++){
        num_b = num_b * 10 + b[i] - '0';
    }
    cout<<num_a+num_b-c<<'\n';
    string a_b = a+b;
    int num_k = 0;
    for(int i=0; i<a_b.length(); i++){
        num_k = num_k * 10 + a_b[i] - '0';
    }
    cout<<num_k - c<<'\n';
    return 0;
}