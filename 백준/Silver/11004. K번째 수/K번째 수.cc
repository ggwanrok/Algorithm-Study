#include <bits/stdc++.h>

using namespace std;

priority_queue<int> pq;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin>>n>>k;
    while(n--){
        int i;
        cin>>i;
        if(pq.size() < k) pq.push(i);
        else{
            if(i < pq.top()){
                pq.pop();
                pq.push(i);
            }
        }
    }
    cout<<pq.top()<<'\n';
    return 0;
}

//set
// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     set<int> s;
//     int n, k;
//     int tar = 1;
//     cin>>n>>k;
//     while(n--){
//         int c;
//         cin>>c;
//         s.insert(c);
//     }
//     for(int curr : s){
//         if(tar == k){
//             cout<<curr<<'\n';
//             break;
//         }
//         tar++;
//     }

//     return 0;
// }

//실5 라서 그냥 돌려봤지만, 역시나 시간초과.
// int n, k;
// vector<int> a;

// int main(){
//     cin>>n>>k;
//     while(n--){
//         int tmp;
//         cin>>tmp;
//         a.push_back(tmp);
//     }
//     sort(a.begin(), a.end());
//     cout<<a[k-1]<<'\n';

//     return 0;
// }