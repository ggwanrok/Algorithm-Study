#include <string>
#include <vector>
#include <set>
#define ll long long

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<ll> s;
    int num = 1;
    while(num <= elements.size()){
        for(int i=0; i<elements.size(); i++){
            ll cur_value = 0;
            for(int j=i; j<i+num; j++){
                cur_value += elements[j%elements.size()];
            }
            s.insert(cur_value);
        }
        num++;
    }
    answer = s.size();
    return answer;
}