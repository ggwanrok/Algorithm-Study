#include <iostream>

using namespace std;
#define Mimax -40000000;

int n, m;
int array[101];
int dp[55][101];

void input();
void dynamicProgramming();
void findResult();
int findMax(int, int);

int main(void){
    input();
    dynamicProgramming();
    findResult();
    return 0;
}

void input(){ 
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    for(int i=1; i<= (n+1)/2; i++){
        for(int j=0; j<n; j++){
            dp[i][j] = Mimax;
        }
    }
    
}

void dynamicProgramming(){
    for(int i=1; i<=(n+1)/2; i++){
        
        for(int j=0; j<n; j++){
            if(i==1){ //1개의 덩어리로 구성하는 구조.
                if(j==0){
                    dp[i][j] = array[j];
                }
                else{
                    if(dp[i][j-1] < 0){
                        dp[i][j] = array[j];
                    }
                    else{
                        dp[i][j] = dp[i][j-1] + array[j];
                    }
                }
            }
            else{
                if(j<2*i-2) continue;

                dp[i][j] = (findMax(i-1, j-2) + array[j] > dp[i][j-1] + array[j])? findMax(i-1, j-2) + array[j] : dp[i][j-1] + array[j];
            }

        }
    }
}

int findMax(int i, int j){
    int max = Mimax;
    for(int a=0; a<= j; a++){
        max = (max > dp[i][a]) ? max : dp[i][a];
    }
    return max;
}

void findResult(){
    int res = Mimax;
    for(int i=0; i<n; i++){
        res = (res > dp[m][i]) ? res : dp[m][i];
    }
    cout<<res<<endl;
}
