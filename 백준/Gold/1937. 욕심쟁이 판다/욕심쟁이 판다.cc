#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int area[505][505];
int dpArray[505][505];
int maxValue;
vector<pair<int, pair<int, int>>> valueOfArea;

void input();
void dp();
void output();


int main(void){
    input();
    dp();
	output();
    return 0;
}

void input(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int k;
            cin>>k;
			maxValue = (maxValue < k) ? k : maxValue;
            area[i][j] = k;
			dpArray[i][j] = 1;
            valueOfArea.push_back({k, {i, j}});
        }
    }
    sort(valueOfArea.begin(), valueOfArea.end(), [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        return a.first < b.first;
    });
    
}

void dp(){
    for(int i=0; i<valueOfArea.size(); i++){
		int a = valueOfArea[i].second.first;
        int b = valueOfArea[i].second.second;
		int k= dpArray[a][b];
        if(area[a][b] > area[a-1][b]){
            k =(1 + dpArray[a-1][b] > k ) ? 1 + dpArray[a-1][b] : k;
        }
        if(area[a][b] > area[a+1][b]){
        	k =1 + dpArray[a+1][b] > k ? 1 + dpArray[a+1][b] : k;
        }
        if(area[a][b] > area[a][b-1]){
        	k =1 + dpArray[a][b-1] > k ? 1 + dpArray[a][b-1] : k;
        }
        if(area[a][b] > area[a][b+1]){
        	k =1 + dpArray[a][b+1] > k ? 1 + dpArray[a][b+1] : k;
        }
		dpArray[a][b] = k;
		
	}
}

void output(){
    int k = 0;
    for(int i=1; i<= n; i++){
        for(int j=1; j<= n; j++){
            k = max(k, dpArray[i][j]);
        }
    }
    cout<<k<<'\n';
}