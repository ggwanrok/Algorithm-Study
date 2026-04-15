#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  vector<int> v;
  int n; cin>>n;
  for(int i=0;i<n;i++){
    int a; cin>>a;
    v.push_back(a);
  }
  sort(v.begin(),v.end());
  for(int i=0;i<v.size();i++){
    cout << v[i] << '\n';
  }
 
}