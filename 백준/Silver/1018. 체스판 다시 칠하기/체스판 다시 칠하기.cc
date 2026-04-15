#include <iostream>
using namespace std;





int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int Min = 65;
    int cnt1=0;
    int cnt2=0;
    int n, m;
    cin>>n>>m;
    
    char map[52][52]={0, };
    const char bw[8][9] = {
        {"BWBWBWBW"},
        {"WBWBWBWB"},
        {"BWBWBWBW"},
        {"WBWBWBWB"},
        {"BWBWBWBW"},
        {"WBWBWBWB"},
        {"BWBWBWBW"},
        {"WBWBWBWB"}
        };
    const char wb[8][9] = {
        {"WBWBWBWB"},
        {"BWBWBWBW"},
        {"WBWBWBWB"},
        {"BWBWBWBW"},
        {"WBWBWBWB"},
        {"BWBWBWBW"},
        {"WBWBWBWB"},   
        {"BWBWBWBW"}
        };
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }

    for(int x=0;x<=n-8;++x){
        for(int y=0;y<=m-8;++y){
            for(int i=0;i<8; ++i){
                for(int j=0;j<8;++j){
                    if(map[i+x][j+y] != wb[i][j]){
                        cnt1++;
                    }
                    if(map[i+x][j+y] != bw[i][j]){
                        cnt2++;
                    }
                }
            }
            if(cnt1<cnt2){
                if(Min> cnt1){
                    Min=cnt1;
                }
            }
            else{
                if(Min>cnt2){
                    Min=cnt2;
                }
            }
            cnt1 =0;
            cnt2 =0;
        }
    }
    cout<<Min;
    return 0;
}