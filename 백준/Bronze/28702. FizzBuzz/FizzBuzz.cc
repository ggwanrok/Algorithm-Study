#include <bits/stdc++.h>

using namespace std;

string a, b, c;
int res;
int main(){
    cin>>a>>b>>c;
    res = 0;
    if(a != "Fizz" && a != "Buzz" && a != "FizzBuzz"){
        for(int i=0; i<a.length(); i++){
            res = res * 10 + a[i] - '0';
        }
        res += 3;
    }
    else if(b != "Fizz" && b != "Buzz" && b != "FizzBuzz"){
        for(int i=0; i<b.length(); i++){
            res = res * 10 + b[i] - '0';
        }
        res += 2;
    }
    else {
        //여기까지 왔으면 어차피 얘는 숫자여야 한다.
        for(int i=0; i<c.length(); i++){
            res = res * 10 + c[i] - '0';
        }
        res += 1;
    }
    if(res % 15 == 0){
        cout<<"FizzBuzz"<<'\n';
    }
    else if(res % 5 == 0){
        cout<<"Buzz"<<'\n';
    }
    else if( res % 3 == 0){
        cout<<"Fizz"<<'\n';
    }
    else {
        cout<<res<<'\n';
    }
    return 0;
}