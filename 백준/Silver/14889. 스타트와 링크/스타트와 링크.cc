#include <bits/stdc++.h>

using namespace std;

int N;
int S[21][21];
bool visited[21];
int min_diff = 1e9;

void calculate() {
    int start_team = 0;
    int link_team = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (visited[i] && visited[j]) start_team += S[i][j];
            if (!visited[i] && !visited[j]) link_team += S[i][j];
        }
    }

    int diff = abs(start_team - link_team);
    if (diff < min_diff) min_diff = diff;
}

void dfs(int idx, int cnt) {
    if (cnt == N / 2) {
        calculate();
        return;
    }

    for (int i = idx; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i + 1, cnt + 1);
            visited[i] = false; 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> S[i][j];
        }
    }

    dfs(1, 0);
    cout << min_diff << endl;

    return 0;
}