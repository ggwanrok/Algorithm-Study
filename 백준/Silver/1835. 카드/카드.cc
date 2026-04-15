#include <bits/stdc++.h>

using namespace std;

deque<int> v;

int n;
//1 = 1, 2 = 1 + 2 해당 숫자로부터 i+1만큼 더해준 뒤, n으로 나눈 나머지 자리에 있어야 함.
/*
1번 카드는 0+i+1 % n 에 위치.
2번카드는 이전 
01002000300004000005
210
1 4 8 13 ... 번쨰 인덱스에 들어가야 하는데,
1 0 0 1
01002
(i + (i+1)) 자리에 넣어야 하나?
*/

int main(void){
	cin>>n;
	//i번쨰 숫자는 지금까지 0~i까지 더해준 뒤에 존재해야 한다.
	int m = n;
	while(m>=1){
		v.push_front(m);
		int k = m;
		while(k>=1){
			int x = v.back();
			v.pop_back();
			v.push_front(x);
			k--;
		}
		m--;
	}
	for(int i=0; i<n; i++){
		cout<<v[i]<<" ";
	}

	return 0;
}