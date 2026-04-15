#include <iostream>
using namespace std;
struct person {
    string name;
    int age;
    int wei;
    string aka;
    person(string name, int age, int wei,string aka):name(name), age(age), wei(wei){}
};
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    while(1){
        string na; int ag; int we;
        cin>>na>>ag>>we;
        person p1 = person(na, ag, we,"");
        if(p1.name == "#" && p1.age == 0 && p1.wei == 0) break;
        if(p1.age > 17 || p1.wei >= 80){
            p1.aka = "Senior";
        }
        else{
            p1.aka = "Junior";
        }
        cout<<p1.name<<" "<<p1.aka<<'\n';
    }
    return 0;
} 
