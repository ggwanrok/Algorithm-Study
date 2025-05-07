#include <bits/stdc++.h>

using namespace std;

map<string, float> m;
vector<pair<float, string>> v;

float sum_score;
float sum_grade;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    m["A+"] = 4.5;
    m["A0"] = 4.0;
    m["B+"] = 3.5;
    m["B0"] = 3.0;
    m["C+"] = 2.5;
    m["C0"] = 2.0;
    m["D+"] = 1.5;
    m["D0"] = 1.0;
    m["F"] = 0.0;
    sum_score = 0.0;
    sum_grade = 0.0;
    for(int i=0; i<20; i++){
        string a, c; float b;
        cin>>a>>b>>c;
        if(c == "P") continue;
        sum_score += b;
        v.push_back({b, c});
    }

    for(auto cur : v){
        float scr = cur.first;
        string gra = cur.second;
        sum_grade += (scr * m[gra]);
    }
    cout<<sum_grade/sum_score<<'\n';
    
    return 0;
}