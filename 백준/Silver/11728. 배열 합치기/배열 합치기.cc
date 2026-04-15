#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
vector<int> v2;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin>>n>>m;
    for(int i=0; i<n; ++i){
        int k; cin>>k;
        v.push_back(k);
    }
    for(int i=0; i<m; ++i){
        int k; cin>>k;
        v.push_back(k);
    }
    int l =0; int r =n;
    while(1){
        if(v[l]<v[r]){
            v2.push_back(v[l]);
            l++;
        }
        else if(v[r]<v[l]){
            v2.push_back(v[r]);
            r++;
        }
        else{
            v2.push_back(v[l]);
            v2.push_back(v[r]);
            l++; r++;
        }
        if(l == n){
            for(int i=r; i<v.size(); ++i){
                v2.push_back(v[i]);
            }
            break;
        }
        if(r == v.size()){
            for(int i=l; i<n; ++i){
                v2.push_back(v[i]);
            }
            break;
        }
    }
    for(int i=0; i<v2.size(); ++i){
        cout<<v2[i]<<" ";
    }

    return 0;
}