#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

struct P{
    ll x;
    ll y;
};

vector<pair<P, P>> line;
//각 선분에 대한 저장을 진행.
//선분들의 정점을 외적을 통해 구역을 특정한다.
//반복하면 될듯?

ll group[3005]; // 각 구룹마다의 보유 선분의 갯수.
ll its_root[3005]; // 각 그룹의 루트인덱스
//그룹에 대한 라벨을 통해서 처리해보자.
ll find(ll);

void input();

//아래 3 함수로 교점이 존재하는가를 판단이 가능.
//외적을 진행하는 함수
ll cross_product(P, P ,P);
//교차점이 존재하는가를 따져봄
bool is_abut(P, P, P, P);
//점이 선분위에 있나를 따져봄.
//ccw 의 결과가 0이라면 이 작업을 해줘야 정확한 해석 가능
bool is_in_line(P, P, P);

void grouping();

ll n;

int main(){
    input();
    grouping();
    ll maximum=0, count = 0;
    for (int i = 0; i < n; i++) {
        ll root = find(i); // 실제 루트를 찾아야 그룹의 크기를 정확히 계산
        if(root == i){
            count++;
            maximum = max(maximum, group[root]);
        }

    }
    cout<<count<<'\n'<<maximum<<'\n';
    return 0;
}

void input(){
    cin>>n;
    P a, b;
    for(int i=0; i<n; i++){
        its_root[i] = i; //본인이 본인 그룹을 가지고 있음.
        group[i] = 1; //그룹의 갯수도 1
        ll a_x, a_y, b_x, b_y;
        cin>>a_x>>a_y>>b_x>>b_y;
        if(a_x < b_x){
            a = {a_x, a_y};
            b = {b_x, b_y};
        }
        else if(a_x == b_x){
            if(a_y <= b_y){
                a = {a_x, a_y};
                b = {b_x, b_y};
            }
            else {
                a = {b_x, b_y};
                b = {a_x, a_y};
            }
        }
        else{
            a = {b_x, b_y};
            b = {a_x, a_y};
        }
        line.push_back({a, b});
    }
}

ll find(ll t){
    if(its_root[t] == t) return t;
    return its_root[t] = find(its_root[t]);
}

void grouping(){
    for(int i=0; i<n; i++){
    //전반적으로 for문을 2중으로 돌려주면서, 만약, 겹치는게 있다? 그럼 바깥의 그룹으로 합쳐주자.
        for(int j=0; j<n; j++){
            ll root_a = find(i);
            ll root_b = find(j);
            if(root_a != root_b){
                //서로 다른 그룹일 때, 교점이 있는지를 판단해서 있다면 같은 그룹으로 만들어주기.
                if(is_abut(line[i].first, line[i].second, line[j].first, line[j].second)){
                    group[root_a] += group[root_b];
                    group[root_b] = group[root_a];
                    if(root_a < root_b) its_root[root_b] = root_a;
                    else its_root[root_a] = root_b;

                }
            }
        }
    }
}

ll cross_product(P a, P b, P c) {
    long long k = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if(k > 0) return 1;
    else if(k < 0) return -1;
    else return 0;
}

bool is_in_line(P a, P b, P c) {
    if (c.x <= max(a.x, b.x) && c.x >= min(a.x, b.x) &&
        c.y <= max(a.y, b.y) && c.y >= min(a.y, b.y))
        return true;
    return false;
}


bool is_abut(P a, P b, P c, P d) {
    ll d1 = cross_product(a, b, c);
    ll d2 = cross_product(a, b, d);
    ll d3 = cross_product(c, d, a);
    ll d4 = cross_product(c, d, b);

    // 교차 여부 확인
    if (d1 * d2 < 0 && d3 * d4 < 0)
        return true;

    // 특수한 경우: 세 점이 일직선상에 있을 때
    if (d1 == 0 && is_in_line(a, b, c)) return true;
    if (d2 == 0 && is_in_line(a, b, d)) return true;
    if (d3 == 0 && is_in_line(c, d, a)) return true;
    if (d4 == 0 && is_in_line(c, d, b)) return true;

    return false;
}