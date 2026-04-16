#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c;
    cin>>a>>b>>c;
    
    int res = a * b * c;
    vector<int> v(10, 0);
    while(res>0){
        int value = res % 10;
        res /= 10;
        v[value]++;
    }
    for(int i=0; i<10; i++){
        cout<<v[i]<<'\n';
    }
    return 0;


}