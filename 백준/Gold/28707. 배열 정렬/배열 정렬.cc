#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// 구조체: 현재 배열 상태와 비용을 저장
struct State {
    vector<int> arr;
    int cost;
    bool operator>(const State &other) const {
        return cost > other.cost;
    }
};

// 전역 변수 선언
int N, M;
vector<int> start_arr, target_arr;
vector<tuple<int, int, int>> swaps;

int dijkstra();

int main() {
    // 배열 크기 입력
    cin >> N;
    start_arr.resize(N);
    
    for (int i = 0; i < N; i++) cin >> start_arr[i];

    // 목표 상태 (비내림차순 정렬)
    target_arr = start_arr;
    sort(target_arr.begin(), target_arr.end());

    // 스왑 연산 개수 입력
    cin >> M;
    swaps.resize(M);
    
    for (int i = 0; i < M; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        swaps[i] = {l, r, c};
    }

    // 다익스트라 실행 및 결과 출력
    cout << dijkstra() << '\n';
}


int dijkstra() {
    priority_queue<State, vector<State>, greater<State>> pq;
    unordered_map<string, int> dist;

    pq.push({start_arr, 0});
    dist[to_string(start_arr[0])] = 0;

    while (!pq.empty()) {
        State now = pq.top();
        pq.pop();

        // 목표 상태 도달 시 최소 비용 반환
        if (now.arr == target_arr) return now.cost;

        // 현재 상태에서 가능한 모든 스왑 연산 수행
        for (int i = 0; i < M; i++) {
            int l = get<0>(swaps[i]) - 1;
            int r = get<1>(swaps[i]) - 1;
            int c = get<2>(swaps[i]);

            vector<int> next_arr = now.arr;
            swap(next_arr[l], next_arr[r]);
            int next_cost = now.cost + c;

            string key = "";
            for (int x : next_arr) key += to_string(x) + ","; // 구분자 추가

            if (dist.find(key) == dist.end() || dist[key] > next_cost) {
                dist[key] = next_cost;
                pq.push({next_arr, next_cost});
            }
        }
    }

    return -1; // 도달 불가능한 경우
}
