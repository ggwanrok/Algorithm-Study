//start 01:23
#include <bits/stdc++.h>

using namespace std;

deque<int> input_arr;
vector<int> res;

int main(){
    int n, k;
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        input_arr.push_back(i);
    }
    int cnt = 1;
    while(!input_arr.empty()){
        if(k == cnt){
            cnt = 1;
            res.push_back(input_arr.front());
            input_arr.pop_front();
        }
        else{
            int tmp = input_arr.front();
            input_arr.pop_front();
            input_arr.push_back(tmp);
            cnt++;
        }
    }
    for(int i=0; i<res.size(); i++){
        if(i == 0) cout<<'<';
        cout<<res[i];
        if(i != res.size()-1){
            cout<<", ";
        }
        if(i == res.size()-1) cout<<">\n";
    }

    return 0;
}
//end : 01:27