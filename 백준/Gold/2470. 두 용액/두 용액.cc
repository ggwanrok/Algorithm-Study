#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
pair<ll, pair<ll, ll> > p;
ll arr[100001];
int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> arr[i];
    }
    sort(arr, arr+N);
    p.second.first = arr[0];
    p.second.second = arr[N-1];
    p.first = p.second.first + p.second.second;
    int f = 0, l = N-1;
    while (f<l) {
        if(abs(arr[f]+arr[l]) < abs(p.first)) {
            p.first = arr[f]+arr[l];
            p.second.first = arr[f];
            p.second.second = arr[l];
        }
        if(abs(arr[f]) < abs(arr[l])){
            l-=1;
        }
        else f+=1;
    }
    cout << p.second.first << ' ' << p.second.second << '\n';
    
}