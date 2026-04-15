#include <iostream>

using namespace std;

int greedy(int arr[], int size, int target){
    int count = 0;
    int value=0;
    int index =0;
    while(true){
        value += arr[index];
        if(target < value){
            value -= arr[index];
            index++;
        }
        else{
            count++;
        }
        if(index == size){
            break;
        }
    }
    return count;
}


int main(void){
    int n, k;

    cin>>n>>k;

    int arr[n];

    for(int i=n-1; i>=0; i--){
        int value;
        cin>>value;
        arr[i] = value;
    }

    cout<<greedy(arr, n, k);

    return 0;
}