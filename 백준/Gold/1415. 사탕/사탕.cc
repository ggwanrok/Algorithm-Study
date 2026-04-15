#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int candy[10000]; // 사탕의 가격 별 갯수
long long sumTo[500000]; //해당 숫자가 만들어질 수 있는 가짓수.
bool checkPrime[500000]; // 만들어진 숫자가 소수인가를 판단
vector<int> speciesCandy; // 사탕의 종류가 담겨져있는 벡터
int n, t; // input의 단위
long long sum_MAX; // 모든 사탕을 사용했을 때, 나오는 가격
int var_MAX; // 단일 제품중 최고가
int zeroCount; // 0의 갯수에 따라서, 만들어질 수 있는 경우가 배로 늘어나기에, 0은 따로 체크를 한다.
long long finalResult; // 최종으로 출력될 값.

//finalResult와 sumTo는 반드시 long long이어야 한다.
//해당 가격이 만들어질 수 있는 경우와 finalResult가 int값을 넘어갈 수 있다.
//이 두개만 long long으로 해도 문제는 풀리지만,
//94행에 i*i를 사용해 시간을 줄이기 위해선,
//해당 i, j도 long long으로 줄여줄 수 있다.



//필요한 값을 입력받아서, 사탕의 종류와, 종류별 갯수를 저장.
void input();

//sumTo 배열 업데이트 함수
void setPrice();

//에라토스테네스의 체
void setPrimeNumber();

//소수들 중에서 유효한 값들을 걸러내고, 0의 갯수와 조합하여 답 출력
void resultPrice();

int main(void){
    input();
    setPrice();
    setPrimeNumber();
    resultPrice();
    return 0;
}


void input(){
    cin>>n;
    zeroCount = 1; //기본 상태
    sum_MAX = 0;
    var_MAX = 0;
    finalResult = 0;
    int k;
    for(int i=0; i<n; i++){
        cin>>k;
        if(k == 0){
            zeroCount++;
            continue;
        }
        candy[k]++;
        sum_MAX += k;
        var_MAX = (var_MAX > k) ? var_MAX : k;
    }
    for(int i=0; i<=var_MAX; i++){
        if(candy[i] != 0){
            speciesCandy.push_back(i);
        }
    }
}

void setPrice(){
    sumTo[0] = 1;

    for(int i=0; i<(int)speciesCandy.size(); i++){
        int k = speciesCandy[i]; //사탕의 가격
        
        //바텀업을 할 경우, 갯수에 대한 제한 처리에 어려움이 있다고 느낌.
        //탑다운을 통해서, 해당 갯수를 처리하는 도중에 업데이트 할 부분이 있다면 업데이트를 해준다.
        for(int total = sum_MAX; total >= 0; total--){
            for(int j=1; j <= candy[k]; j++){
                if(total < k*j) break;
                sumTo[total] += sumTo[total - k*j];
            }
        }
    }
}

void setPrimeNumber(){
    memset(checkPrime, true, sizeof(checkPrime));
    checkPrime[0] = false;
    checkPrime[1] = false;  
    for(long long i=2; i<=(sum_MAX); i ++){
     for(long long j=i*i; j<=sum_MAX; j+=i){
        checkPrime[j] = false;
     }   
    }
}

void resultPrice(){
    for(int i=0; i<=sum_MAX; i++){
        if(checkPrime[i] == false) continue;
        finalResult += sumTo[i];
    }
    cout<<finalResult*zeroCount<<endl;
}