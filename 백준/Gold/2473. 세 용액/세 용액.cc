#include <bits/stdc++.h>
#define ll long long

using namespace std;


ll res = 3000000001;
int res_1, res_2, res_3;
int n;
vector<ll> solution;

void input();
void func();
void output();

int main(void){
    input();
    func();
    output();
    return 0;
}

void func(){
    for(int p2=1; p2<n-1; p2++){
        int p1 = 0, p3 = n-1;
        while(p1<p2 && p2<p3){
            ll sum = solution[p1] + solution[p2] + solution[p3];
            if(abs(sum) < abs(res)){
                res = sum;
                res_1 = solution[p1];
                res_2 = solution[p2];
                res_3 = solution[p3];
            }
            if(sum < 0) p1++;
            else p3--;
        }
        
    }
}

void input(){
    cin>>n;
    for(int i=0; i<n; i++){
        ll k;
        cin>>k;
        solution.push_back(k);
    }
    sort(solution.begin(), solution.end());
}

void output(){
    cout<<res_1<<" "<<res_2<<" "<<res_3<<'\n';
}