#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for(auto c : str){
        cout<<c<<'\n';
    }
    return 0;
}