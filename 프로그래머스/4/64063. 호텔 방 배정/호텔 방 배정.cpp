#include <string>
#include <vector>
#include <unordered_map>
#define ll long long
using namespace std;

ll get_par(ll idx, unordered_map<ll, ll> & m){
    if(m.find(idx) != m.end()){
        return m[idx] = get_par(m[idx], m);
    }
    return idx;
}


vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;
    unordered_map<ll, ll> m;
    for(ll i=0; i<room_number.size(); i++){
        if(m.find(room_number[i]) != m.end()){
            m[room_number[i]] = get_par(room_number[i], m);
            m.insert({m[room_number[i]], m[room_number[i]]+1});
            answer.push_back(m[room_number[i]]);
        }
        else{
            answer.push_back(room_number[i]);
            m.insert({room_number[i], room_number[i]+1});
        }
        
    }
    return answer;
}