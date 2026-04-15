#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    int n = 1000 - t;
    int c=500;
    int cnt =0;
    while(1){
        if(n>=c){
            n -= c;
            cnt++;
        }
        else{
            c = 100;
            if(n>=c){
                n -= c;
                cnt++;
            }
            else{
                c = 50;
                if(n>=c){
                    n -= c;
                    cnt++;
                    }
                else{
                    c = 10;
                    if(n>=c){
                        n -= c;
                        cnt++;
                        }
                        else{
                            c= 5;
                            if(n>=c){
                                n -= c;
                                cnt++;
                            }
                            else{
                                c = 1;
                                if(n>=c){
                                    n -= c;
                                    cnt++;
                                }
                            }
                            }
                        }
                    }
                }
    if(n==0){
        cout<<cnt;
        break;
    }
    }
    return 0;
}