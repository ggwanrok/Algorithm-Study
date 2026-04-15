#include <iostream>
#include <cstring>

using namespace std;

string array;
int checkPalindrome[2505][2505];
int dpPalindrome[2505][2505];

void input();
void findPalindrome();
void updatePalindrome(int, int);
void findBest();

int main(void){
    input();
    findPalindrome();

    cout<<dpPalindrome[array.size()][array.size()];
 
    return 0;
}

void input(){
    cin>>array;
}

void updatePalindrome(int start, int end){
    if(end >= array.size()){
        return;
    }
    
    int pCheck = 1;
    for(int i=0; i<=(end-start+1)/2; i++){
        if(array[start + i] != array[end-i]){
            pCheck = 0;
            break;
        }
    }
    if(pCheck == 1){

        checkPalindrome[start+1][end+1] = 1;
    }
        
    updatePalindrome(start, end+1);
}

void findBest(){
    for(int i=0; i<=array.size(); i++){
        dpPalindrome[0][i] = 3000;
    }

    for(int i=1; i<=array.size(); i++){
        for(int j=1; j<=array.size(); j++){
            
            if(i>j){
                dpPalindrome[i][j] = dpPalindrome[i-1][j];
            }
            else if(i == 1){
                if(checkPalindrome[i][j] == 1){
                    dpPalindrome[i][j] = dpPalindrome[i][i-1] +1;
                }
                else{
                    dpPalindrome[i][j] = dpPalindrome[i][j-1] +1;
                }
            }
            else{
                int k = 0;
                if(checkPalindrome[i][j] == 1){
                    k = dpPalindrome[i][i-1] + 1;
                }
                else{
                    k = dpPalindrome[i][j-1] +1;
                }
                dpPalindrome[i][j] = (dpPalindrome[i-1][j] < k) ? dpPalindrome[i-1][j] : k;
            }
        }
    }
    
}

void findPalindrome(){
    for(int i=0; i<array.size(); i++){
        updatePalindrome(i, i);
    }
    
    findBest();

}