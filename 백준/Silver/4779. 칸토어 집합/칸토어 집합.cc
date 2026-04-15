#include <iostream>
#include <cmath>
using namespace std;

void method(char *array, int start, int end)
{
    if (end - start <= 1)
    {
        return;
    }
    int size_1 = start + (end - start + 1) / 3;
    int size_2 = start + 2 * (end - start + 1) / 3;
    for (int i = size_1; i < size_2; i++)
    {
        array[i] = ' ';
    }
    method(array, start, size_1);
    method(array, size_2, end);
}

int main(void)
{
    int N;

    while (cin >> N)
    {

        char *array;
        int len = pow(3, N);
        array = new char[len];

        for (int i = 0; i < len; i++)
        {
            array[i] = '-';
        }

        method(array, 0, len);

        for (int i = 0; i < len; i++)
        {
            cout << array[i];
        }
        cout<<'\n';

        delete[] array;
    }

    return 0;
}
