#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++){
        cout<<"Class "<<i<<'\n';
        int num; cin>>num;
        int gap = 0;
        vector<int> ss;
        while(num--){
            int score; cin>>score;
            ss.push_back(score);
        }
        sort(ss.begin(), ss.end());
        for(int i=0; i<ss.size()-1; i++){
            gap = max(gap, ss[i+1]-ss[i]);
        }
        cout<<"Max "<<ss[ss.size()-1]<<", Min "<<ss[0]<<", Largest gap "<<gap<<'\n';
    }
    return 0;
}