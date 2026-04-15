#include <iostream>
#include <queue>
#include <set>

using namespace std;

int area[1001][1001]; //입력을 받고, 수정된 정보를 출력할 판
int label_area[1001][1001]; //0들이 붙어있는 구역을 뭉쳐서 라벨링해준 뒤 저장.
int area_size[1000001]; //라벨링된 구역이 각각 어떤 크기인지를 저장
bool visit_area[1001][1001]; //zero_labeling 시에 방문여부를 판단할 간단한 배열
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m;

void input();
void zero_labeling();
void searching();
void output();

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    zero_labeling();
    searching();
    output();
    return 0;
}

void input(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string input;
        cin>>input;
        for(int j=0; j<m; j++){
            area[i][j] = input[j] -'0';
        }
    }
}
void output(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<area[i][j]%10;
        }
        cout<<'\n';
    }
}

void zero_labeling(){
    int label = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(area[i][j] == 0 && !visit_area[i][j]){
                label++;
                visit_area[i][j] = true;
                label_area[i][j] = label;
                int count = 1;
                queue<pair<int, int>> check_zero;
                check_zero.push({i, j});
                while(!check_zero.empty()){
                    pair<int, int> cur = check_zero.front();
                    check_zero.pop();
                    for(int i=0; i<4; i++){
                        int after_x = cur.first + dx[i];
                        int after_y = cur.second + dy[i];
                        if(after_x>=0 && after_x<=n-1 && after_y>=0 && after_y<=m-1){
                            if(area[after_x][after_y] == 0 && !visit_area[after_x][after_y]){
                                count++;
                                visit_area[after_x][after_y] = true;
                                check_zero.push({after_x, after_y});
                                label_area[after_x][after_y] = label;
                            }
                        }
                    }
                }
                //label 변수가 있고, 해당 변수값을 각 구역에 대해서 라벨 번호는 붙여준 상태이다. 
                //그리고 각 라벨이 어떤 숫자를 가지고 있는지만 기록하면 됨.
                area_size[label] = count;
            }
        }
    }
}

void searching(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(area[i][j] == 1){
                int res = area[i][j];
                set<int> is_used;//얘를 사용해서, 이미 사용된 구역인지를 체크하도록 함.
                for(int di=0; di<4; di++){
                    int after_x = i + dx[di];
                    int after_y = j + dy[di];
                    if(after_x>=0 && after_x<=n-1 && after_y>=0 && after_y<=m-1){
                        if(area[after_x][after_y] == 0){
                            if(is_used.find(label_area[after_x][after_y]) == is_used.end()){
                                is_used.insert(label_area[after_x][after_y]);
                                res += area_size[label_area[after_x][after_y]];
                            }
                        }
                    }
                }
                area[i][j] = res;
            }
        }
    }
}
