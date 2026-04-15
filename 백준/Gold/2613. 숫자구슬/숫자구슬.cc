#include <iostream>
using namespace std;

int n, m;
int array[302];
int Left;
int Right;
int res;

bool checkM(int mid){
    int mCheck = 1;
    int targetSum = 0;

    for(int i=0; i<n; i++){
        if(targetSum + array[i] > mid){
            targetSum = 0;
            mCheck++;
        }
        targetSum += array[i];
    }
    return mCheck <= m;
}

void parametricSearch(){
    while(Left <= Right){
        int mid = (Left + Right)/2;
        if(checkM(mid)){
            res = mid;
            Right = mid-1;
        }
        else{
            Left = mid+1;
        }
    }
}

void printGroup(){
    int count = 0;
    int groupSum = 0;
    int yetToM = m;
    //0부터 인덱스를 꾸려나가고, 초과한다면 넘겨주는 형식을 고려한다.
    for(int i=0; i<=n; i++){
        if(groupSum + array[i] > res || yetToM > n - i){
            cout<<count<<" ";
            count = 0;
            groupSum = 0;
            yetToM--;
        }
        groupSum += array[i];
        count++;
    }
}

int main(void){
    cin>>n>>m;
    Left = 0;
    Right = 0;
    for(int i=0; i<n; i++){
        cin>>array[i];
        Right += array[i];
        Left = (Left > array[i])? Left : array[i];
    }

    parametricSearch();

    cout<<res<<'\n';
    
    printGroup();

    return 0;
}
