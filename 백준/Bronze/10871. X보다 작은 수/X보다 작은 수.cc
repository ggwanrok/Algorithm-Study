#include <iostream>
#include <vector>

using namespace std;
int main() {
  int n; cin>>n;
  int x; cin>>x;
  vector<int> v;
  for(int i=0;i<n;i++){
    int c; cin>>c;
    v.push_back(c);
  }
  for(int i=0;i<n;i++){
    if(v[i]<x){
      cout<<v[i]<<" ";
    }
  }
}