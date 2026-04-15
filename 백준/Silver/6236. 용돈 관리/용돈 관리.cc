#include <iostream>

using namespace std;

int n, m;
int totalMoney; //전체 출금금액
int minimum; // 이놈 이상으로는 뽑아야 무리가 없다.

int days[100001];
int checkTotalMoney();

bool isItPossible(int price){ 
    if(minimum >price){
        return false;
    }

    int priceOutCount = 1;
    int currentCash = 0;
    
    for(int i=0; i<n; i++){
        if(currentCash+days[i] > price){
            currentCash = days[i];
            priceOutCount++;
        }
        else{
            currentCash += days[i];
        }
    }
    
    //주어진 price로 내가 몇번의 출금을 해야하는지 정보를 구했다.
    // m보다 많이 뽑는다면, 값이 작기에 너무 많이 뽑은 것 -> 값을 늘려줘야겠지.
    // m보다 적게 뽑는다면, 값이 크기 떼문에 너무 적게 뽑은 것. -> 값을 줄여줘야겠지.
    // m과 같은 값을 가진다면, 값을 줄여가나서 최적화 시켜야 한다. -> 값을 줄인다.
    return m >= priceOutCount;
}

int findBestPrice(){
    int left = 1;
    int right = totalMoney;
    
    while(left < right){
        int mid = (left + right)/2;
        if(isItPossible(mid) == true){
            //값을 줄여줘야 한다.
            right = mid;
        }
        else{
            left = mid+1;
        }
    }
    //위 식을 반복하다보면, 이분탐색을 진행하다가, 결국 가장 적합한 값이 left로 오게 되는 구조.
    return left;
}




int main(void){
    cin>>n>>m;
    minimum = 0;
    totalMoney = checkTotalMoney();
    
    int finalPrice = findBestPrice();

    cout<<finalPrice<<'\n';
    return 0;
}

int checkTotalMoney(){
    int k=0;
    for(int i=0; i<n; i++){
        int input;
        cin>>input;
        days[i] = input;
        k += input;
        minimum = (minimum > days[i]) ? minimum : days[i];
    }
    return k;
}