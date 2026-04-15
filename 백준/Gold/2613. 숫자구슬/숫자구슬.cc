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
    //옳바른 targetNum을 구하는 과정.
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
            //기존에는 while문에 등호를 뺴고, right = mid로 구성했었지만, check함수가 등호를 포함한 결과를 가져옴.
            //따라서, 전처럼 진행한다면, 옳바른 값보다 1 작은 값이 도출될 수 있음.
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
    //이미 되는 targetNum을 구한 것.
    //되는 과정 하나만 보이면 되는 상황이기에, 아래처럼 풀이함.
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
