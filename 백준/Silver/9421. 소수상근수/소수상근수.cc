#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<bool> number(1000001, true);
int check[487];
int n;

int main(void){
	cin>>n;
	number[0] = false, number[1] = false;

	for(int i=2; i*i <= n; i++){
		if(number[i]){
			for(int j=i*i; j<=n; j+=i){
				number[j] = false;
			}
		}
	}
	for(int i=2; i<=n; i++){
		if(!number[i]) continue;
		
		memset(check, 0, sizeof(check));
		bool suc = true;
		int num = i; // num을 변동시키면서 작업해줄거임.
		while(num != 1){
			int sum = 0;
			while(num){
				sum += (num%10)*(num%10);
				num /= 10;
			}
			if(check[sum]){
				suc = false;
				break;
			}
			check[sum] = 1;
			num = sum;
		}
		if(suc) cout<<i<<'\n';

	}

	return 0;
}