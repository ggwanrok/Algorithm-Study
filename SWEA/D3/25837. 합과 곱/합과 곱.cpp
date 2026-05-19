#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        ll s, p;
        int flag = 1;
        cin>>s>>p;
        ll le = 1;
        ll ri = s/2;
        while(le <= ri){
        	ll mid = (le+ri)/2;
            ll another = s-mid;
            if(p%mid == 0 and p/mid == another){
            	flag = 0;
                cout<<"Yes\n";
                break;
            }
            if(mid > p/another){
            	ri = mid -1;
            }
            else{
            	le = mid+1;
            }
        }
        if(flag) cout<<"No\n";
    }
        
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}