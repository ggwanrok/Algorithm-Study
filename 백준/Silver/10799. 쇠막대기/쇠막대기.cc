#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string data_str;
    getline(cin, data_str);

    ll res = 0;
    int cur_stick = 0;

    for(int i=0; i<data_str.length(); i++){
        if(data_str[i] == '('){
            if(data_str[i+1] == '('){
                cur_stick++;
            }
            else{
                res += cur_stick;
                i++;
            }
        }
        else{
            cur_stick--;
            res += 1;
        }
    }
    cout<<res<<'\n';
    
    return 0;
}