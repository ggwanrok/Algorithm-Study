#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char arr_1[1001];
char arr_2[1001];
int editArr[1001][1001];

int arr_1_length;
int arr_2_length;

int main(void){
	for(int i = 0; i < 2 ; i++){
		string input;
		cin>>input;
		if(i==0){
			arr_1_length = input.length();
			for(int j=0; j<input.length(); j++){
				arr_1[j+1] = input[j];
			}
		}
		else{
			arr_2_length = input.length();
			for(int j=0; j<input.length(); j++){
				arr_2[j+1] = input[j];
			}
			
		}
	}
	for(int i = 0 ; i <= arr_1_length; i++){
		
		for(int j=0; j<=arr_2_length; j++){
			if(i==0){
				editArr[i][j] = j;
				continue;
			}
			if(j==0){
				editArr[i][j] = i;
				continue;
			}
			int var = (arr_1[i] == arr_2[j])? 0: 1;
			editArr[i][j] = min(min(editArr[i-1][j] + 1, editArr[i][j-1]+1), editArr[i-1][j-1] + var);
			
			
			
		}
	}
	cout<<editArr[arr_1_length][arr_2_length];
	
	return 0;	
}