#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    while(true){
        int k; cin>>k;
        if(k == 0) break;
        vector<int> v;
        vector<int> flag_v;
        flag_v.resize(k, 0);
        for(int i=0; i<6; i++){
            flag_v[i] = 1;
        }
        for(int i=0; i<k; i++){
            int num; cin>>num;
            v.push_back(num);
        }
        do{
            for(int i=0; i<k; i++){
                if(flag_v[i] != 0) cout<<v[i]<<' ';
            }
            cout<<'\n';
        } while(prev_permutation(flag_v.begin(), flag_v.end()));
        cout<<'\n';
    }

    return 0;
}