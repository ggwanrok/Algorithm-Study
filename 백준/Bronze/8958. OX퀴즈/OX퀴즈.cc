#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    string str;
    int cnt =0;
    int sum =0;
    int mom =0;
    int n; cin>>n;
    for(int i=0;i<n;++i){
        cin>>str;
        for(int i=0;i<str.length();++i){
            if(i==0){
                if(str[0] == 'O') cnt =1;
            }
            else{
                if(str[i-1]=='O' && str[i] =='O'){
                    cnt++;
                    if(sum != 0){
                        sum ++;
                    }
                    else sum =1;

                    mom += sum;
                }
                else if(str[i] == 'O'){
                    cnt++;
                }
                else if(str[i] == 'X'){
                    sum =0;
                }
            } 
        }
         cout<<mom+cnt<<'\n';
         mom =0;
         cnt =0;
         sum =0;
    }

    return 0;
}