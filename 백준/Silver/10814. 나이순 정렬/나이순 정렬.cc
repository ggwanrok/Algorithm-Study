#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct person{
    int age;
    string name;
    int cnt;
    person(int age, string name, int cnt):age(age), name(name), cnt(cnt){}
};
bool cmp(person a, person b){
    if(a.age == b.age){
        return a.cnt < b.cnt;
    }
    return a.age < b.age;
}
vector <person> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    for(int i=0; i<n; ++i){
        int a; string b;
        cin>>a>>b;
        v.push_back(person(a, b, i));
    }
    sort(v.begin(), v.end(), cmp);
    for(vector <person> :: iterator it = v.begin(); it != v.end(); ++it){
        cout<<it->age<<" "<<it->name<<'\n';
    }
}