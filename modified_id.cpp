#include <bits/stdc++.h>

using namespace std;

void modify(int id[], int size, int missing[])
{
    for (int i = 0; i < 9; i++)
    {
        int val = id[i];
        for (int j = 1 + i; j < 9; j++)
        {
            if (val == id[j])
            {
                id[j] = missing[i];
            }
        }
    }
}

int main()
{
    int id[] = {2, 1, 1, 0, 1, 1, 0, 4, 2};
    int missing_dig[10];
    int size = 9;
    int k = 0;

    for (int i = 0; i <= 9; i++)
    {
        bool flag = false;
        for (int j = 0; j < 9; j++)
        {
            if (i == id[j])
            {
                flag = true;
            }
        }
        if (!flag)
        {
            missing_dig[k] = i;
            k++;
        }
    }

    modify(id, k, missing_dig);

    for (int i = 0; i < 9; i++)
    {
        cout << id[i] << " ";
    }
    return 0;
}