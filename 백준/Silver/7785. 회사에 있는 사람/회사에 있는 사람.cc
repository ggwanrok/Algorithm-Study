#include <set>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
set<string> s;
vector<string> v;
int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; ++i){
        string a, b;
        cin >> a >> b;
        if(b == "enter") {
            s.insert(a);
        }
        else{
            s.erase(a);
        }
    }
    for(set<string>::iterator it=s.begin(); it!=s.end(); ++it){
        v.push_back(*it);
    }
    for(int i=v.size()-1; i>=0; --i){
        cout << v[i] << '\n';
    }
}
