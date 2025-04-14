#include <bits/stdc++.h>

using namespace std;
long long n;
long long fb[77];
long long get_fb(long long k){
    if(fb[k] != -1) return fb[k];
    if(k < 2) return 1;
    if(k == 2) return 2;
    if(k == 3) return 4;
    return fb[k] = get_fb(k-1) + get_fb(k-2) + get_fb(k-3) + get_fb(k-4);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    fill(fb, fb+75, -1);
    while(n--){
        long long num; cin>>num;
        cout<<get_fb(num)<<'\n';
    }
    return 0;
}