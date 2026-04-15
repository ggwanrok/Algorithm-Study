#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>

using namespace std;
int main() {
  int n; cin>>n;
  queue<int> q;
  for(int i=1;i<=n;i++){
    q.push(i);
  }
  while(q.empty() == 0){
    int k = q.front();
    q.pop();
    cout<<k<<" ";
    if(q.empty() == 0){
      k=q.front();
      q.pop();
      q.push(k);
    }
  }
}