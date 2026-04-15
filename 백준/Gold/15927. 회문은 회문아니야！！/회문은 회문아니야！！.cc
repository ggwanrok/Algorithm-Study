#include <iostream>

using namespace std;

string s_input;

bool isPalindrome(string s) {
    int n = s.length();
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n-1-i]) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>s_input;

    if(isPalindrome(s_input)){
        int flag = 0;
        for(int i=1; i<s_input.length(); i++){
            if(s_input[0] != s_input[i]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout<<-1<<'\n';
        }
        else{
            cout<<s_input.length()-1<<'\n';
        }
    }
    else{
        cout<<s_input.length()<<'\n';
    }
    return 0;
}