#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

string s_1;
string s_2;

vector<char> v_1;
vector<char> v_2;

stack<char> s;

int LcsArray[1005][1005];

void input();
void findLCS();
void findRoute(int, int);
void output();

int main(void){
    input();
    findLCS();
    findRoute(v_1.size()-1, v_2.size()-1);
    output();
    

    return 0;
}

void input(){
    cin>>s_1>>s_2;

    v_1.push_back('0');
    v_2.push_back('0');

    for(int i=0; i<s_1.size(); i++){
        v_1.push_back(s_1[i]);
    }
    for(int i=0; i<s_2.size(); i++){
        v_2.push_back(s_2[i]);
    }

    for(int i=0; i<=v_1.size(); i++){
        LcsArray[i][0] = 0;
    }
    for(int i=0; i<=v_2.size(); i++){
        LcsArray[0][i] = 0;
    }

}

void findLCS(){
    for(int i=1; i<v_1.size(); i++){
        for(int j=1; j<v_2.size(); j++){
            if(v_1[i] == v_2[j]){
                LcsArray[i][j] = LcsArray[i-1][j-1]+1;
            }
            else{
                LcsArray[i][j] = (LcsArray[i-1][j] > LcsArray[i][j-1] ? LcsArray[i-1][j] : LcsArray[i][j-1]);
            }
        }
    }
}

void findRoute(int i, int j){
    if(LcsArray[i][j] == 0){
        return;
    }
    
    if(LcsArray[i][j] > LcsArray[i-1][j] && LcsArray[i][j] > LcsArray[i][j-1]){
        s.push(v_1[i]);
        findRoute(i-1, j-1);
    }
    else if(LcsArray[i][j] == LcsArray[i-1][j]){
        findRoute(i-1, j);
    }
    else{
        findRoute(i, j-1);
    }
}

void output(){
    cout<<LcsArray[v_1.size()-1][v_2.size()-1]<<endl;
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
}