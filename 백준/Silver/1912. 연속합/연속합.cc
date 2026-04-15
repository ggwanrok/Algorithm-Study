#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main(void){
    int n;
    cin>>n;

    for(int i=0; i<n; i++){ // 입력받을 수를 저장할 녀석.
        int k;
        cin>>k;
        v.push_back(k);
    }

    int sum, max; // 수를 더해갈 녀석 sum, 최댓값을 저장할 녀석 max.
    sum = 0;
    max = 0;

    for(int i=0; i<n; i++){
        if(i==0){
            max += v[i];
        }
        sum += v[i];

        max = (sum > max) ? sum : max;
        
        if(sum < 0){
            sum = 0;
        }
        
    }

    cout<<max<<'\n';

    return 0;
}