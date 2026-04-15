#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, f; 
    cin>>n>>f;
    int k = (n/100)*100;
    for(int i=0; i<100; i++){
        if((k+i)%f == 0){
            if(i<10){
                cout<<"0"<<i;
                return 0;
            }
            else{
                cout<<i;
                return 0;
            }
        }
    }
    return 0;
}