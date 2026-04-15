#include <bits/stdc++.h>
#define MAX 100005
#define ll long long
#define MAX_SUM 1000000000
using namespace std;
/*
 * 각 노드마다, 고유 번호가 있고,
 * 간선은 서로 다른 가중치를 가지고 있다.
 * 선택의 기준이 되는 방식도 결국, 간선이기 때문에,
 * 간선에 대해서 코딩을 해 나아가는 방식을 구성해야겠네
 * 그렇다면, 해당 노드의 root를 나타내는 배열을 만들고,
 * 각 간선 무게마다의 방향성을 나타내는 배열 2개를 만들자.
 */
/*
 * 최초로 각 노드들을 입력받는다면, 그들은 서로에 대한 그룹이 각자인 상태로 시작.
 * 간선의 가중치가 큰 것을 기준으로 서로 다른 그룹에 속해있다면 각 그룹의 생성 가능한 쌍 만큼 최종 결과에 더해주면 된다.
 * 그 뒤에 두 그룹을 하나의 그룹으로 만들어주는 과정을 도입해나가면 될듯 하다.
 * 어차피 각 노드의 숫자는 모두 달라서 각 요소들의 갯수 만큼의 곱으로 해당 지점에서 채워줄 수 있을 것.
 */
/*
 * 단순하게, 모두 끊어져 있는 상태에서, 서로 다른 그룹이라면, 두 그룹을 합쳐주고, 만들어질 수 있는 조합만큼 sum값을 더해주고,
 * sum 값은 풀이합쳐지는데 사용되는 weight 만큼 빼주면서 진행해보자.
 */
int t_about_u[MAX];
int t_about_v[MAX];
int its_root[MAX];
int count_group_size[MAX];
int n, m;
ll res;
ll sum_of_weight;

void input();
int find(int);

void get_cost();


int main(){
    input();
    get_cost();
    return 0;
}

void get_cost(){
    for(int i=100000; i>0; i--){
        if(t_about_v[i]){ //해당 가중치가 존재한다면, u, v가 같은 그룹인지를 따져봐야겠지.
            int group_u = find(t_about_u[i]);
            int group_v = find(t_about_v[i]);
            if(group_u != group_v){
                //서로 다르다면, 해당 간선이 제거되면서 서로 다른 그룹으로 나눠졌음을 의미한다.
                //따라서 해당 간선이 제거된 상태의 sum값을 갯수만큼 처리를 해준다. 그리고 같은 그룹으로 만들어줘야지.
                res = res + sum_of_weight * count_group_size[group_u] * count_group_size[group_v];
                its_root[group_v] = group_u;
                count_group_size[group_u] += count_group_size[group_v];
            }
            //sum 값을 줄여줘야 한다.
            sum_of_weight -= i;
        }
    }
    cout<<res%MAX_SUM<<'\n';
}

void input(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        its_root[i] = i;
        count_group_size[i] = 1;
    }
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        t_about_u[c] = a;
        t_about_v[c] = b;
        sum_of_weight = (sum_of_weight + c);
    }
}

int find(int t){
    if(its_root[t] == t) return t;
    return its_root[t] = find(its_root[t]);
}

