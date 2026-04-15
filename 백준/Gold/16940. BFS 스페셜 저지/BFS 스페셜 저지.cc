#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> edge[100001];

vector<int> q;

queue<int> bfs;

int main(void)
{
    int size;
    cin >> size;

    for (int i = 0; i < size - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for (int i = 0; i < size; i++)
    {
        int k;
        cin >> k;
        q.push_back(k);
    }
    int index = 0, position, count;

    if (q[index] != 1)
    {
        cout << "0" << '\n';
        return 0;
    }

    bfs.push(1);

    index++;

    while (!bfs.empty())
    {
        position = bfs.front();
        bfs.pop();
        position == 1 ? count = edge[position].size() : count = edge[position].size() - 1;
        while (count)
        {
            auto now = find(edge[position].begin(), edge[position].end(), q[index]);
            if (now != edge[position].end())
            {
                edge[position].erase(now);
                if (edge[q[index]].size() > 1)
                    bfs.push(q[index]);
                count--;
                index++;
            }
            else
            {
                cout << "0" << '\n';
                return 0;
            }
        }
    }

    cout << "1" << '\n';

    return 0;
}
