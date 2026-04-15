#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool comp(int A, int B){
    if(A <= B) {
        return A > B;
    }
    return A > B;
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    
    char arr[11]= {};
    cin>>arr;
    int len = strlen(arr);
    sort(arr, arr + len, comp);
    cout<<arr;
    

    return 0;
}