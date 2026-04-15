#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

queue<int> wei; //최소시간을 구해야하는 대상건물들
vector<vector<int>> v; //선행관계를 알 수 있게하는 벡터
int building[501]; // 단순건물 완성 시간
int finalbuilding[501]; // 최종건물 완성 시간
vector<int> pre; // 선행건물의 갯수

int main(void)
{
    int n; // 건물의 갯수
    cin >> n;
    int k = 0;
    v.resize(n);
    pre.resize(n);

    for (int i = 0; i < n; ++i) { // 건물의 갯수만큼 입력을 받아서 값을 채워줌
		cin >> building[i];
		finalbuilding[i] = building[i];

		int in;
		while (cin >> in) { // 선행건물의 정보를 받아서, v의 인덱스마다 나중에 지어지는 건물정보를 담는다.
			if (in == -1) break;
			--in;

			v[in].emplace_back(i);
			++pre[i]; // 해당 건물이 지어지기 전, 선행건물의 갯수를 담는다.
		}
	}

    
    for (int i = 0; i < n; i++){ // 선행건물이 남지 않은 건물을 wei에 담아준다.
        if(pre[i] == 0){
            finalbuilding[i] = building[i];
            wei.push(i);
        }
    }
    
    while(!wei.empty()){ // wei를 비워내면서, 해당 건물을 선행건물로 가지고 있는 건물에 대한 정리를 해준다.
        int k = wei.front();
        wei.pop();

        for(auto next : v[k]) {
            finalbuilding[next] = max(finalbuilding[next], finalbuilding[k] + building[next]);
            if(--pre[next] == 0){
                wei.push(next);
            }
        }

    }

    for(int i=0; i<n; i++){ // wei가 마침내 비워지게 되면, 모든 건물이 최종적으로 최적화 되기 때문에, 답을 출력한다.
        cout<<finalbuilding[i]<<'\n';
    }

    return 0;
}
