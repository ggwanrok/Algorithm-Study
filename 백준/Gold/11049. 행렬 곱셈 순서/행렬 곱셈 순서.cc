#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

long long matrix[2][501];
long long M[501][501];
long long n;

int main(void){
	cin>>n;
	for(long long i=0; i<n; i++){
		long long r, c;
		cin>>r>>c;
		matrix[0][i] = r;
		matrix[1][i] = c;
	}
	for(long long i=0; i<n; i++){
		for(long long j=0; j<n; j++){
			if(i>=j) M[i][j] = 0;
			else{
				M[i][j] = 3000000000;
			}
		}
	}

	//간극을 제어 할 것
	for(long long d=1; d<n; d++){
		for(long long i=0; i<n-d; i++){
			long long j=i+d;
			for(long long k=i;k<j; k++){
				long long x = M[i][k] + M[k+1][j] + matrix[0][i]*matrix[1][k]*matrix[1][j];
				M[i][j] = min(x, M[i][j]);
			}
		}
	}

	cout<<M[0][n-1]<<'\n';


	return 0;
}