#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> num;

vector<int> lis;


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
    lis.push_back(num[0]);
    for(int i=1; i<num.size(); i++){
        int last = lis.size()-1;
        if(num[i] < lis[last]){
            //가야하는 자리에 넣어줌.
            auto iter = lower_bound(lis.begin(), lis.end(), num[i]);
            lis[iter-lis.begin()] = num[i];
        }
        else if(num[i] > lis[last]){
            lis.push_back(num[i]);
        }
    }
}

void input(){
    cin>>n;
    for(int i=0; i<n; i++){
        int c; cin>>c;
        num.push_back(c);
    }
}

void output(){
    cout<<lis.size()<<'\n';
}