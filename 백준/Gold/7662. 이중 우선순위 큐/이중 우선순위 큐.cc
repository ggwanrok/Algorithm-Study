#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int k;
        cin >> k;

        priority_queue<int> max_heap; // 최대 힙
        priority_queue<int, vector<int>, greater<int>> min_heap; // 최소 힙
        unordered_map<int, int> entry_finder; // 힙에 있는 각 값의 개수 기록

        for (int i = 0; i < k; ++i) {
            char command;
            int num;
            cin >> command >> num;

            if (command == 'I') {
                max_heap.push(num);
                min_heap.push(num);
                entry_finder[num]++;
            } else if (command == 'D') {
                if (num == 1) { // 최댓값 삭제
                    while (!max_heap.empty() && entry_finder[max_heap.top()] == 0) {
                        max_heap.pop();
                    }
                    if (!max_heap.empty()) {
                        int max_val = max_heap.top();
                        max_heap.pop();
                        entry_finder[max_val]--;
                    }
                } else if (num == -1) { // 최솟값 삭제
                    while (!min_heap.empty() && entry_finder[min_heap.top()] == 0) {
                        min_heap.pop();
                    }
                    if (!min_heap.empty()) {
                        int min_val = min_heap.top();
                        min_heap.pop();
                        entry_finder[min_val]--;
                    }
                }
            }
        }

        // 유효한 최댓값과 최솟값 찾기
        while (!max_heap.empty() && entry_finder[max_heap.top()] == 0) {
            max_heap.pop();
        }
        while (!min_heap.empty() && entry_finder[min_heap.top()] == 0) {
            min_heap.pop();
        }

        if (max_heap.empty() || min_heap.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << max_heap.top() << ' ' << min_heap.top() << '\n';
        }
    }

    return 0;
}
