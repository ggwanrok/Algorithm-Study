#include <iostream>

using namespace std;

int main(void){

    int N, M;
    cin>>N>>M;

    int input[N+1][N+1];

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            input[i][j] = 1000000000;
        }
    }

    for(int i=0; i<M; i++){
            int a, b, c;
            cin>>a>>b>>c;

            input[a][b] = c;        
        
    }

    
    for(int k=1; k<=N; k++){ 
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(input[i][k] + input[k][j] < input[i][j]){
                    input[i][j] = input[i][k] + input[k][j];
                }
            }
        }
    }

    int mini = 1000000000;
    for(int i=1; i<=N; i++){
        int val = input[i][i];
        mini = (mini < val) ? mini : val;
    }

    if(mini == 1000000000){
        cout<<"-1"<<'\n';
        
    }
    else{
        cout<<mini<<'\n';
    }

    // for(int i=1; i<=N; i++){
    //     for(int j=1; j<=N; j++){
    //         cout<<input[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    return 0;
}