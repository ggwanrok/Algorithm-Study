#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	
	for(test_case = 1; test_case <= 10; ++test_case)
	{
		int cnt; cin>>cnt;
        vector<int> hei(101, 0);
        for(int i=0; i<100; i++){
            int k; cin>>k;
            hei[k]++;
        }
		int mini = 1;
        int maxi = 100;
        
        while(hei[mini] <= 0){
            	mini++;
            }
            while(hei[maxi] <= 0){
            	maxi--;
            }
        
        while(abs(maxi-mini) > 1 and cnt--){
            hei[maxi]--;
            hei[maxi-1]++;
            hei[mini]--;
            hei[mini+1]++;
            if(hei[maxi] <= 0){
            	hei[maxi] = 0;
            }
            if(hei[mini] <= 0){
            	hei[mini] = 0;
            }
            while(hei[mini] <= 0){
            	mini++;
            }
            while(hei[maxi] <= 0){
            	maxi--;
            }
        }
		cout<<"#"<<test_case<<' '<<maxi-mini<<'\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}