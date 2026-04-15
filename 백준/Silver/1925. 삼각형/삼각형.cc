#include <bits/stdc++.h>
using namespace std;
int dist(int x1, int y1, int x2, int y2){
    return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}
int main(){
    int x1,x2,x3,y1,y2,y3; cin>>x1>>y1>>x2>>y2>>x3>>y3;
    int ta=dist(x1,y1,x2,y2);
    int tb=dist(x2,y2,x3,y3);
    int tc=dist(x3,y3,x1,y1);
    int a=max({ta,tb,tc});
    int c=min({ta,tb,tc});
    int b=ta+tb+tc-a-c;
    if(sqrt(a)>=sqrt(b)+sqrt(c)){
        cout << "X\n";
    }
    else if(a==b && b==c){
        cout << "JungTriangle\n";
    }
    else if(a==b){
        cout << "Yeahkak2Triangle\n";
    }
    else if(b==c){
        if(b+c==a){
            cout << "Jikkak2Triangle\n";
        }
        else{
            cout << "Dunkak2Triangle\n";
        }
    }
    else if(b+c==a){
        cout << "JikkakTriangle\n";
    }
    else if(b+c<a){
        cout << "DunkakTriangle\n";
    }
    else{
        cout << "YeahkakTriangle\n";
    }
}
