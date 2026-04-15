#include <bits/stdc++.h>

using namespace std;

/*
만약, mid를 이용한 값이, 목표 갯수보다 

- left = mid + 1 처리할 떄.

많이 나올 경우,
해당 거리로는 답이 될 수 없다. 거리를 늘려야 한다.
같게 나올 경우,
해당 거리로는 답이 될 수도 있다. 극한의 경우를 쨰기 위해서 거리를 늘려야 한다.


- right = mid 처리할 때.

작게 나올 경우,
거리를 줄여야 한다.

설치도 첫집에 하는게 무조건 이득이다.
최대 거리를 측적하려는거라서, 가장 먼저 알박기 하나 해둬야 나쁠게 전혀 없다.
*/

vector<int> v;

bool estimate(int d, int c){
    int cnt = 1;
    int last = v[0];

    for(int i=1; i< v.size(); i++){
        if(v[i]-last >= d){
            cnt++;
            last = v[i];
        }
    }

    return cnt >= c;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, c;
    cin>>n>>c;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        v.push_back(k);
    }

    sort(v.begin(), v.end());
    int le = 1;
    int ri = v[v.size()-1] - v[0];
    int res;
    while(le<=ri){
        int mid = (le+ri)/2;
        if(estimate(mid, c)){
            le = mid + 1;
            res = mid;
        }
        else{
            ri = mid - 1;
        }
    }

    cout<<res<<'\n';

    return 0;
}