#include <iostream>

using namespace std;

int n;
double scores[1001];
double maxi = 0;
double sum = 0;
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>scores[i];
        maxi = maxi < scores[i] ? scores[i] : maxi;
    }
    for(int i=0; i<n; i++){
        sum += scores[i];
    }
    double res = sum * 100 / maxi / n ;
    cout<<res<<'\n';
    return 0;
}