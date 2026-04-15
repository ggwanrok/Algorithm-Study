#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> tower;
vector<int> cnt;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        tower.push_back(k);
    }
    cnt.resize(tower.size(), 0);

    for(int i=tower.size()-1; i>=0; i--){
        while(1){
            if(pq.empty()){
                cnt[i] = 0;
                break;
            }
            int lowest_high = pq.top().first;
            if(tower[i] > lowest_high){
                cnt[pq.top().second] = i+1;
                pq.pop();
            }
            else{
                break;
            }
        }
        pq.push({tower[i], i});
    }

    for(int i=0; i<cnt.size(); i++){
        cout<<cnt[i]<<' ';
    }
    cout<<'\n';

    return 0;
}