#include <bits/stdc++.h>

using namespace std;

int func(int n)
{
    int count = 1;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = (3 * n) + 1;
        }
        count++;
    }
    return count;
}

int main()
{
    int min, max, cmax, value, i, j;
    cmax = 0;

    while (cin >> i >> j)
    {
        if (i < j)
        {
            min = i;
            max = j;
        }
        else
        {
            min = j;
            max = i;
        }

        for (int k = min; k <= max; k++)
        {
            value = func(k);
            if (cmax < value)
                cmax = value;
        }

        cout << i << " " << j << " " << cmax << endl;
        cmax = 0;
    }

    return 0;
}