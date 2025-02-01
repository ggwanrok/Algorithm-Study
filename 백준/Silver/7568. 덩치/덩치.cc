#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> person(n); // 몸무게, 키 저장
    vector<int> rank(n, 1); // 모든 사람의 초기 등수를 1로 설정

    for (int i = 0; i < n; i++) {
        cin >> person[i].first >> person[i].second; // 몸무게, 키 입력
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue; // 자기 자신은 비교 안 함
            if (person[j].first > person[i].first && person[j].second > person[i].second) {
                rank[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << rank[i] << " ";
    }
    cout << "\n";

    return 0;
}
