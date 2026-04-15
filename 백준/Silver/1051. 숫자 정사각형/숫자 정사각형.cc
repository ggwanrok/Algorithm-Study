#include <iostream>
#include <string>
using namespace std;
string s[51];
int n, m;
int li =1;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; ++i){
        cin>>s[i];
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            for(int a=1; a+j<m; ++a){
                if(a+i<n){
                    if(s[i][j] == s[i][j+a] && s[i][j] == s[i+a][j] && s[i][j] == s[i+a][j+a]){
                        li = max(li, (a+1)*(a+1));
                    }
                }
            }
        }
    }
    cout<<li<<'\n';
}

