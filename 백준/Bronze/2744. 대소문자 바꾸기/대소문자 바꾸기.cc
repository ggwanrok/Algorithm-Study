#include <iostream>
#include <string>

using namespace std;
int main() {
  string s;
  cin>>s;
  int t = s.size();
  for(int i=0;i<t;i++){
   if(s[i] >= 65 && s[i] <= 90){
     s[i]+=32;
   }
    else{
      s[i] = s[i] - 32;
    }
  }
  cout<<s;
}