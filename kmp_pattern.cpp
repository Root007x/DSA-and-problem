#include <bits/stdc++.h>

using namespace std;

string pattern = "mahadi";   // input pattern
string text = "I am mahadi"; // input text

void lpsarray(string pattern, int lps[], int size)
{
    lps[0] = 0;
    int i = 0, j = 1;

    while (j < size)
    {
        if (pattern[i] == pattern[j])
        {
            lps[j++] = i + 1;
            i++;
        }
        else
        {
            (i == 0) ? lps[j++] = 0 : i = lps[--i];
        }
    }
}

void patten_match(int lps[], int size)
{
    int i = 0, j = 0, count = 0;
    while (i < text.size())
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
            count++;
        }
        else
        {
            (j == 0) ? (lps[j] = 0, i++) : (j = lps[--j], count = j);
        }
    }

    if (count == size)
    {
        cout << "Pattern Exist" << endl;
    }
    else
    {
        cout << "Pattern Does not exist" << endl;
    }
}

int main()
{

    int size = pattern.size();
    int lps[size];

    lpsarray(pattern, lps, size);
    patten_match(lps, size);

    return 0;
}