#include <bits/stdc++.h>

using namespace std;

void missing_digit()
{
    int id = 211011042;
    int val, i;
    bool flag = false;

    for (i = 0; i < 10; i++)
    {
        while (id != 0)
        {
            val = id % 10;
            if (val == i)
            {
                flag = true;
                break;
            }
            id = id / 10;
        }
        if (!flag)
        {
            cout << i << " ";
        }
        flag = false;
        id = 211011042;
    }
}

int main()
{
    missing_digit();
    return 0;
}