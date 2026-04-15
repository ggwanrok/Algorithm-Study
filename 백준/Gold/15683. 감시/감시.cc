#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> map(8,vector<int>(8,0));
vector<vector<int>> map_copy(8,vector<int>(8,0));
int n,m;
int answer;
vector<vector<int>> cameras; //카메라 종류,위치를 기록하는 k*3크기의 벡터
//5개종류의 카메라마다 4가지 방향에대해 4개 방향의 보는 여부 기록
vector<vector<vector<bool>>> see_dirs(5,vector<vector<bool>>(4, vector<bool>(4,0))); 
//5개의 카메라 종류마다 상하좌우 방향을 바라볼때 지도에서 보는방향 기록하는 함수
void See_dir(){ //카메라 종류, 행위치, 열위치, 보는방향(상하좌우 0123)
	//1번카메라
	see_dirs[0][0] = {1,0,0,0};//상
	see_dirs[0][1] = {0,1,0,0}; //하
	see_dirs[0][2] = {0,0,1,0}; //좌
	see_dirs[0][3] = {0,0,0,1}; //우
	//2번카메라
	see_dirs[1][0] = {1,1,0,0}; //상
	see_dirs[1][1] = {1,1,0,0}; //하
	see_dirs[1][2] = {0,0,1,1}; //좌
	see_dirs[1][3] = {0,0,1,1}; //우
	//3번카메라
	see_dirs[2][0] = {1,0,1,0}; //상
	see_dirs[2][1] = {0,1,0,1}; //하
	see_dirs[2][2] = {0,1,1,0}; //좌
	see_dirs[2][3] = {1,0,0,1}; //우
	//4번카메라
	see_dirs[3][0] = {1,1,1,0}; //상
	see_dirs[3][1] = {1,1,0,1}; //하
	see_dirs[3][2] = {0,1,1,1}; //좌
	see_dirs[3][3] = {1,0,1,1}; //우
	//5번카메라
	see_dirs[4][0] = {1,1,1,1}; //상
	see_dirs[4][1] = {1,1,1,1}; //하
	see_dirs[4][2] = {1,1,1,1}; //좌
	see_dirs[4][3] = {1,1,1,1}; //우
	
	return;
}

//카메라 정보와 보는방향이 주어지면 그 한방향에 대해 map체크하는 함수
void Check_map(int row, int col, int dir){
	if(dir==0){ //상
		for(int i = row; i>=0; i--){
			if(map[i][col]==6){
				break;
			}
			if(map[i][col]==0){
				map[i][col] = 9;
			}
		}
	}
	else if(dir==1){ //하
		for(int i = row; i<n; i++){
			if(map[i][col]==6){
				break;
			}
			if(map[i][col]==0){
				map[i][col] = 9;
			}
		}
	}
	else if(dir==2){ //좌
		for(int j = col; j>=0; j--){
			if(map[row][j]==6){
				break;
			}
			if(map[row][j]==0){
				map[row][j] = 9;
			}
		}
	}
	else{ //우
		for(int j = col; j<m; j++){
			if(map[row][j]==6){
				break;
			}
			if(map[row][j]==0){
				map[row][j] = 9;
			}
		}
	}
	return;
}

//map에서 사각지대 개수 세서 반환
int Count_blind(){
	int cnt = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(map[i][j]==0)
				cnt++;
		}
	}
	return cnt;
}

//dfs로 k개의 카메라 방향 정하는 함수
void Dfs(string camera_dirs, int k){ //카메라들 보는방향k개를 string으로, 카메라개수
	//k개의 카메라 보는 방향 정했으면 
	if(camera_dirs.size()==k){
		map_copy = map;
		//k개의 카메라가 바라보는 방향의 map체크
		for(int i = 0; i<k; i++){
			//i번 카메라의 종류는 1~5
			if(see_dirs[cameras[i][0]-1][camera_dirs[i]-'0'][0]){ //상
				Check_map(cameras[i][1], cameras[i][2],0);
			}
			if(see_dirs[cameras[i][0]-1][camera_dirs[i]-'0'][1]){ //하
				Check_map(cameras[i][1], cameras[i][2],1);
			}
			if(see_dirs[cameras[i][0]-1][camera_dirs[i]-'0'][2]){ //좌
				Check_map(cameras[i][1], cameras[i][2],2);
			}
			if(see_dirs[cameras[i][0]-1][camera_dirs[i]-'0'][3]){ //우
				Check_map(cameras[i][1], cameras[i][2],3);
			}
		}
		//map에서 사각지대 개수 세서 answer최소값 갱신
		int cnt = Count_blind();
		if(answer>cnt){
			answer = cnt;
		}
		map = map_copy;
		return;
	}
	for(int i = 0; i<4; i++){
		char one = i+'0';
		camera_dirs += one;
		Dfs(camera_dirs, k);
		camera_dirs.erase(camera_dirs.size()-1, 1);
	}
	return;
}

int main() {
	//8*8크기의 배열을 만들고 m*n크기에 지도를 받아온다. 동시에 사용한 카메라정보를 2차원 벡터 cameras에 저장
	cin>>n>>m;
	int k;
	answer = 100; //최대 100안넘는다
	vector<int> temp(3,0); //1개의 카메라마다 3개의 정보 필요
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin>>map[i][j];
			if(map[i][j]!=0 && map[i][j]!=6){
				temp[0] = map[i][j]; //종류
				temp[1] = i; //row
				temp[2] = j; //col
				cameras.push_back(temp);
			}
		}
	}
	See_dir();
	
	//dfs로 k개의 카메라 방향을 다 정하고, map에서 사각지대 체크
	Dfs("", cameras.size());
	//체크가 끝나면 지도를 훑으며 사각지대의 개수를 세고, answer의 최소값을 갱신
	cout<<answer;
	return 0;
}