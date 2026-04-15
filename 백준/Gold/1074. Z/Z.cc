#include <iostream>
using namespace std;
int n, r, c;
int ans;

void z(int y, int x, int size)
{
    if (y == r && x == c)
    {
        cout << ans << '\n';
        return;
    }

    // r,c가 현재 사분면에 존재한다면
    if (r < y + size && r >= y && c < x + size && c >= x)
    {
        // 1사분면 탐색
        z(y, x, size / 2);
        // 2사분면 탐색
        z(y, x + size / 2, size / 2);
        // 3사분면 탐색
        z(y + size / 2, x, size / 2);
        // 4사분면 탐색
        z(y + size / 2, x + size / 2, size / 2);
    }
    else
    {
        ans += size * size;
    }
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    cin>>n>>r>>c;
    int t = 1;
    while(n--){// 그림 한 변의 길이를 완성했다.
        t *= 2;
    }
    z(0, 0, t);
    return 0;
} 
