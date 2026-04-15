#include <iostream>
#include <string>
using namespace std;

int target = 0;
int numbers[10] = { 0 };

bool IsCheck(string numStr)
{
    for (int i = 0; i < numStr.length(); ++i)
    {
        if (numbers[numStr[i] - '0'] == 1)
            return false;
    }

    return true;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> target;

    int n;
    cin >> n;

    int removeNum = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> removeNum;
        numbers[removeNum] = 1;
    }

    if (100 == target)
    {
        cout << 0;
        return 0;
    }

    int minDist = abs(target - 100);

    int count = 0;
    string targetNumStr = to_string(target);
    string upNumStr = targetNumStr;
    string downNumStr = targetNumStr;

    if (IsCheck(targetNumStr))
    {
        if (targetNumStr.length() < minDist)
        {
            count += targetNumStr.length();
            cout << count;
        }
        else
            cout << minDist;

        return 0;
    }

    int upNum = target;
    int downNum = target;

    while (true)
    {
        if (minDist < count + upNumStr.length())
        {
            cout << minDist;
            return 0;
        }
        
        if (IsCheck(downNumStr) && 0 <= downNum)
        {
            count += downNumStr.length();
            cout << count;
            return 0;
        }
        else if (IsCheck(upNumStr))
        {
            count += upNumStr.length();
            cout << count;
            return 0;
        }

        ++upNum;
        --downNum;

        upNumStr = to_string(upNum);
        downNumStr = to_string(downNum);
        ++count;
    }

    return 0;
}

