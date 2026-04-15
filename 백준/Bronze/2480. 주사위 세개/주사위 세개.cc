#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cmp(int a, int b){
    if(a<b) return a>b;
    return a>b;
}
vector<int> v;
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int count = 1;
    for(int i=0; i<3; i++){
        int k; cin>>k;
        v.push_back(k);
    }
    sort(v.begin(), v.end(), cmp);
    int c = v[0];
    for(int i = 1; i < v.size(); i++){
        if(v[i] == v[i-1]){
            count++;
            c = v[i];
        }
    }
    if(count == 1){
        cout<< 100 * c;
    }
    else if(count == 2){
        cout<<1000 + 100*c;
    }
    else{
        cout<<10000 + 1000*c;
    }
    return 0;
}