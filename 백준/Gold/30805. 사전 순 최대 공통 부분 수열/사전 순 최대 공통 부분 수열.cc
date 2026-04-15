#include <iostream>
#include <vector>
using namespace std;

// 공통 부분 수열 저장을 위한 2차원 벡터 (각 위치에 vector<int>로 저장)
vector<vector<vector<int>>> area(105, vector<vector<int>>(105));
int n, m;
vector<int> a;  // 첫 번째 수열 (int 타입으로 변경)
vector<int> b;  // 두 번째 수열 (int 타입으로 변경)

void input();  // 입력 함수
vector<int> compare_vectors(vector<int>, vector<int>);  // 사전식 비교 함수
void func();  // 공통 부분 수열 찾기 함수
void output();  // 출력 함수

int main(){
    input();
    func();
    output();
    return 0;
}

void output() {
    // 공통 부분 수열의 길이와 내용을 출력
    cout << area[n][m].size() << '\n';  // 최종 공통 부분 수열의 길이 출력
    for(int num : area[n][m]) {  // 최종 공통 부분 수열 출력
        cout << num << ' ';
    }
    if(area[n][m].size()){
        cout<<'\n';
    }
}

void func() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                // 공통 부분 수열이 확장될 때, 기존 수열에 a[i] 추가
                vector<int> old_sequence = area[i-1][j-1];
                while(!old_sequence.empty() && old_sequence.back() < a[i]){
                    old_sequence.pop_back();
                }
                old_sequence.push_back(a[i]);
                area[i][j] = old_sequence;
            } else {
                // 기존 공통 부분 수열 중 사전순으로 뒤에 오는 것을 선택
                area[i][j] = compare_vectors(area[i-1][j], area[i][j-1]);
            }
        }
    }
}

// 두 vector<int> 중 사전순으로 더 뒤에 오는 벡터를 반환
vector<int> compare_vectors(vector<int> vec1, vector<int> vec2) {
    size_t min_length = min(vec1.size(), vec2.size());
    
    // 첫 번째 요소부터 사전순으로 비교
    for (size_t i = 0; i < min_length; i++) {
        if (vec1[i] != vec2[i]) {
            return (vec1[i] > vec2[i]) ? vec1 : vec2;
        }
    }
    
    // 앞부분이 동일한 경우, 더 긴 벡터가 사전순으로 뒤에 온다고 판단
    return (vec1.size() > vec2.size()) ? vec1 : vec2;
}


void input() {
    cin >> n;
    a.push_back(0);  // 1-based indexing 사용하기 위해 0 추가
    b.push_back(0);

    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        a.push_back(k);  // 첫 번째 수열 입력 (1-based 인덱스)
    }
    
    cin >> m;
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        b.push_back(k);  // 두 번째 수열 입력 (1-based 인덱스)
    }

    // area 벡터 초기화 (기본적으로 비어 있는 상태)
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            area[i][j].clear();
        }
    }
}
