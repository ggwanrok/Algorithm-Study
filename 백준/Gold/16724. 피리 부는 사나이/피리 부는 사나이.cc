#include <bits/stdc++.h>
using namespace std;

int n, m, res;
vector<int> par;  // 부모 노드를 저장할 배열
vector<vector<char>> arr;

void input();
void func();
pair<int, int> next_move(int i, int j);
int find(int x); 
void union_sets(int a, int b);
void output();


int main() {
    input();
    func();
    output();
    return 0;
}

pair<int, int> next_move(int i, int j) {
    if (arr[i][j] == 'D') return {i + 1, j};
    if (arr[i][j] == 'L') return {i, j - 1};
    if (arr[i][j] == 'R') return {i, j + 1};
    if (arr[i][j] == 'U') return {i - 1, j};
}

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);  // 경로 압축
}

void union_sets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) par[a] = b;  // 집합 병합
}

void input() {
    cin >> n >> m;
    arr.assign(n, vector<char>(m));
    par.resize(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n * m; i++) {
        par[i] = i;  // 초기 부모 설정
    }
}

void func() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int curr = i * m + j;
            pair<int, int> nxt = next_move(i, j);
            int next_idx = nxt.first * m + nxt.second;
            union_sets(curr, next_idx);  // 현재 위치와 다음 위치를 연결
        }
    }

    // 모든 노드에 대해 find 호출로 경로 압축
    for (int i = 0; i < n * m; i++) {
        find(i);  // 모든 노드를 최적화
    }

    // 루트 노드 개수 세기
    set<int> unique_cycles;
    for (int i = 0; i < n * m; i++) {
        unique_cycles.insert(find(i));
    }
    res = unique_cycles.size();
}


void output() {
    cout << res << '\n';
}

