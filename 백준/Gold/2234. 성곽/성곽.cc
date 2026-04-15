#include <iostream>
#include <queue>
using namespace std;

int area[55][55]; //입력받을 공간
int room_number[55][55]; //방번호를 통해 이어져 있는 방 구분
bool is_visited[55][55]; //방문여부를 판단
int room_number_db[2555]; //각 방 번호마다의 방 갯수 저장
int n, m;

// 비트연산을 통해서 벽 유무를 확인.
int check_wall[4]={1, 2, 4, 8};
int cal_move[4] = {-1, 0, 1, 0};
int row_move[4] = {0, -1, 0, 1};

int room_count;
int total_max_width_room;
int combine_room_max;

void input();
void do_1_2();
void do_3();

int main(void){
    input();
    do_1_2();
    do_3();
    cout<<room_count<<'\n'<<total_max_width_room<<'\n'<<combine_room_max<<'\n';
    return 0;
}

void input(){
    //가로 세로 길이를 입력받은 뒤,
    //만들어질 수 있는 벽의 범위까지 고려하여 만들어줄 것.
    //방이 아닌 경우도 고려를 해야하나? 일단 무시하기.
    cin>>n>>m;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int k;
            cin>>k;
            area[i][j] = k;
        }
    }
}

void do_1_2(){
    //bfs를 통한 방 정보 탐색
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(is_visited[i][j]) continue;
            room_count++;
            int check_room_size = 1;
            queue<pair<int, int>> bfs;
            bfs.push({i, j});
            is_visited[i][j] = 1;
            room_number[i][j] = room_count;
            while(!bfs.empty()){
                pair<int, int> cur = bfs.front();
                bfs.pop();
                for(int way=0; way<4; way++){
                    int room_info = area[cur.first][cur.second]; //현재 공간의 벽 정보
                    if((room_info & check_wall[way]) == check_wall[way]) continue;

                    int after_y = cur.first + row_move[way]; //이동한 뒤의 행
                    int after_x = cur.second + cal_move[way]; //이동한 뒤의 열
                    
                    if(after_x<0 || after_x>n-1 || after_y<0 || after_y>m-1) continue; //탐색할 수 없는 자리
                    if(is_visited[after_y][after_x]) continue; //이미 탐색

                    //유효한 탐색이다. 큐에 넣어주고, 방 번호를 매겨준 뒤, 방 사이즈를 올려준다.
                    bfs.push({after_y, after_x});
                    is_visited[after_y][after_x] = 1;
                    room_number[after_y][after_x] = room_count;
                    check_room_size++;
                }
            }
            total_max_width_room = (total_max_width_room > check_room_size) ? total_max_width_room : check_room_size;
            room_number_db[room_count] = check_room_size; //각 방 번호마다의 너비를 저장.
        }
    }
}


void do_3(){
    //전체를 탐색하면서, 각 좌표에 이웃한 구역 중에서 서로 다른 room_count를 가지고 있다면, 다른방이다.
    //이 둘의 합의 최댓값을 구해가기.
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            for(int way = 0; way < 4; way++){
                int after_y = i + row_move[way];
                int after_x = j + cal_move[way];
                if(after_x<0 || after_x>n-1 || after_y<0 || after_y>m-1) continue; //탐색할 수 없는 자리
                if(room_number[i][j] == room_number[after_y][after_x]) continue; //같은 구역
                int sum = room_number_db[room_number[i][j]] + room_number_db[room_number[after_y][after_x]];
                combine_room_max = (combine_room_max>sum) ? combine_room_max : sum;
            }
        }
    }
}
