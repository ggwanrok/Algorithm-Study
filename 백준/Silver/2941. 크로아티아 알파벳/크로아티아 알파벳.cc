#include <bits/stdc++.h>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s;
    cin>>s;
    string c_alpla[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    
    int check_cnt=0;
    int cnt=0;
    for(int i=0; i<8; i++){
        size_t pos = s.find(c_alpla[i], 0);
        
        while(pos != string::npos){
            s.replace(pos, c_alpla[i].length(), "*");
            pos = pos - c_alpla[i].length() + 1;
            pos = s.find(c_alpla[i], pos+c_alpla[i].length());
        }
    }
    

    cout<<s.length()<<'\n';

    return 0;
}