#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> people;
int number[1000001];
int num_point[1000001];

void input();
void func();
void output();

int main(){
    input();
    func();
    output();
    return 0;
}

void output(){
    for(int i=0; i<people.size(); i++){
        cout<<num_point[people[i]]<<" ";
    }
}

void func(){
    for(int i=0; i<people.size(); i++){
        int target = people[i];
        int dot = 1;
        while(target * dot <= 1000000){
            //a, b 에서 b를 a가 나눌 수 있다면, a 승인 제도.
            //없다면 반대작업을 해주자.
            if(number[target*dot] == 1){
                num_point[target]++;
                num_point[target*dot]--;
            }
            dot++;
        }
    }
}

void input(){
    cin>>n;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        people.push_back(k);
        number[k] = 1;
    }
}