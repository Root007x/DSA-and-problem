#include <bits/stdc++.h>

using namespace std;

void coin_count(int taka)
{
    int coin[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int counts = 0;

    for (int i = 0; i < 10; i++)
    {
        int mod = taka % coin[i];
        int j = 0;
        while (true)
        {
            int money = coin[i] * j;
            if (taka - money != mod)
            {
                counts++;
                j++;
                continue;
            }
            taka = taka - money;
            break;
        }
        cout << "Coin : " << coin[i] << " : " << counts << endl;
        counts = 0;
    }
}

int main()
{
    int amount = 2792; // your amount
    coin_count(amount);
    return 0;
}