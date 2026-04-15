#include <iostream>
#include <vector>

using namespace std;

vector<long long> v;

int main(void)
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        long long k;
        cin >> k;
        v.push_back(k % m);
    }

    while (v.size() > 1)
    {
        long long k = v.back() % m;
        v.pop_back();
        long long r = v.back() % m;
        v.pop_back();
        
        v.push_back(((k % m) * (r % m)) % m);
    }

    cout << v.front() % m << '\n';

    return 0;
}