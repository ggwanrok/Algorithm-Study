#include <bits/stdc++.h>

using namespace std;

vector<pair<char, char>> input_stream;
string str;

int coin;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    getline(cin, str);
    cin>>coin;
    while(coin--){
        char first = '-';
        char second = '-';
        cin>>first;
        if(first == 'P') cin>>second;
        input_stream.push_back({first, second});
    }

    stack<char> str1;
    stack<char> str2;

    for(auto iter : str){
        str1.push(iter);
    }

    for(auto iter : input_stream){
        if(iter.first == 'L'){
            if(!str1.empty()){
                str2.push(str1.top());
                str1.pop();
            }
        }
        if(iter.first == 'D'){
            if(!str2.empty()){
                str1.push(str2.top());
                str2.pop();
            }
        }
        if(iter.first == 'B'){
            if(!str1.empty()){
                str1.pop();
            }
        }
        if(iter.first == 'P'){
            str1.push(iter.second);
        }
    }
    while(!str1.empty()){
        str2.push(str1.top());
        str1.pop();
    }

    while(!str2.empty()){
        cout<<str2.top();
        str2.pop();
    }
    cout<<'\n';
    return 0;
}