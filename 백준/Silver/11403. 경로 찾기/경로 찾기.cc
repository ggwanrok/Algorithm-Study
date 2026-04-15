#include <iostream>

using namespace std;

int searching(int i, int j){

}

int main(void){

    int N;
    cin>>N;

    int input[N][N];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int k;
            cin>>k;
            if(k==0){
                input[i][j] = 100000;
            }
            else{
                input[i][j] = k;
            }
        }
    }

    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(input[i][k] + input[k][j] < input[i][j]){
                    input[i][j] = input[i][k] + input[k][j];
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(input[i][j] == 100000){
                input[i][j] = 0;
            }
            else{
                input[i][j] = 1;
            }
            cout<<input[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}