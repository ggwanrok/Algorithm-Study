#include <iostream>

using namespace std;

void input();
void updateSum();
void updateDp();
void output();

pair<int, int> area[1505][1505];
pair<int, int> updateArea[1505][1505];
int dp[1505][1505];
int r, c;

int main(void){
    input();
    updateSum();
    updateDp();
    output();

    
    return 0;
}


void input(){
    cin>>r>>c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            string k;
            cin>>k;
            if(k.length() == 2){
                if(k[0] == 'A'){
                    area[i][j] = {k[1]-'0', 0};
                }
                else{
                    area[i][j] = {0, k[1]-'0'};
                }
            }
            else{
                if(k[0] == 'A'){
                    area[i][j] = {(k[1]-'0')*10 + k[2]-'0', 0};
                }
                else{
                    area[i][j] = {0, (k[1]-'0')*10 + k[2]-'0'};
                }
            }
            
        }
    }
}

void updateSum(){
    for(int i=0; i<r; i++){
        updateArea[i][0].first = area[i][0].first;
    }
    for(int i=1; i<r; i++){
        for(int j=1; j<c; j++){
            updateArea[i][j].first = updateArea[i][j-1].first + area[i][j].first;
        }
    }

    for(int j=0; j<c; j++){
        updateArea[0][j].second = area[0][j].second;
    }
    for(int j=1; j<c; j++){
        for(int i=1; i<r; i++){
            updateArea[i][j].second = updateArea[i-1][j].second + area[i][j].second;
        }
    }
}

void updateDp(){
    for(int i=1; i<r; i++){
        for(int j=1; j<c; j++){
            int a, b, c;
            a = dp[i-1][j] + updateArea[i][j-1].first;
            b = dp[i][j-1] + updateArea[i-1][j].second;
            c = dp[i-1][j-1] + updateArea[i][j-1].first + updateArea[i-1][j].second;
            dp[i][j] = max(max(a, b), c);
        }
    }
}

void output(){
    cout<<dp[r-1][c-1]<<'\n';
}