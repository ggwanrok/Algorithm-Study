

#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
string s;
int maxi;
int check[51];

void func(int idx){
    if(idx >= s.length()){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<'\n';
        exit(0);
    }
    //한자리일 때, 두자리일 때.
    //최댓값 이하여야 하고. 아직 체킹이 안된 숫자여야 하낟.
    int num = s[idx]-'0';
    if(check[num] == 0 && num <= maxi){
        check[num] = 1;
        v.push_back(num);
        func(idx+1);
        v.pop_back();
        check[num] = 0;
    }
    if(idx+1 < s.length()){
        int num_2 = (s[idx]-'0') * 10 + s[idx+1]-'0';
        if(check[num_2] == 0 && num_2 <= maxi){
            check[num_2] = 1;
            v.push_back(num_2);
            func(idx+2);
            v.pop_back();
            check[num_2] = 0;
        }
    }

}

int main(){
    cin>>s;
    int len = s.length();
    if(len < 10){
        maxi = len;
    }
    else{
        maxi = (len+9) /2 ;
    }
    func(0);
    return 0;
}