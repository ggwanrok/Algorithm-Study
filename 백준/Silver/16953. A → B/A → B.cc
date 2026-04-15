#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    long k, target;
    int count = 0;
    cin>>target>>k;
    while(1){
        if(k == target){
            count++;
            break;
        }
        else if(k < target){
            count = -1;
            break;
        }
        count++;
        if(k % 10 == 1){
            k = k/10;
        }
        else if(k % 2 == 0){
            k = k/2;
        }
        else{
            count = -1;
            break;
        }
    }
    cout<<count<<'\n';
    return 0;
}