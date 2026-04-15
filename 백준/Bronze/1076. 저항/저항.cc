#include <bits/stdc++.h>
#define ll long long
using namespace std;

string color[10] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
ll idx[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
ll value[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int main(){
    string a, b, c;
    cin>>a>>b>>c;

    int a_idx, b_idx, c_idx;

    for(int i=0; i<10; i++){
        if(color[i] == a){
            a_idx = i;
        }
        if(color[i] == b){
            b_idx = i;
        }
        if(color[i] == c){
            c_idx = i;
        }
    }
    ll res = 0;
    res = (a_idx * 10 + b_idx) * value[c_idx];
    cout<<res<<'\n';
    return 0;
}