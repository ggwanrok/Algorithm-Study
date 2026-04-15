#include <iostream>
#include <cstring>
using namespace std;

char starPoint[5000][10000];

void makeBase(int n){
    starPoint[0][n] = '*';
    starPoint[1][n-1] = starPoint[1][n+1] = '*';
    starPoint[2][n-2] = starPoint[2][n-1] = starPoint[2][n] = starPoint[2][n+1] = starPoint[2][n+2] = '*';

}

void printStar(int n){
    for(int i=0; i<n; i++){
        for(int j=1; j<2*n; j++){
            cout<<starPoint[i][j];
        }
        cout<<'\n';
    }
}

int main(void){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        memset(starPoint[i], ' ', n*2);
    }
    makeBase(n);

    int k = 3;

    while(k < n){
        for(int i=0; i<k; i++){
            for(int j=0; j<2*n; j++){
                if(starPoint[i][j] == '*'){
                    starPoint[i+k][j-k] = starPoint[i+k][j+k] = '*';
                }
            }
        }
        k *= 2;
    }

    printStar(n);

    return 0;
}
