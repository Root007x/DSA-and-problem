#include <bits/stdc++.h>

using namespace std;

int main()
{
    string num1 = "1967591";
    string num2 = "4215";
    string result = "";
    int i = num1.size() - 1, j = num2.size() - 1;
    int sum = 0;
    int carry = 0;

    while (i >= 0 || j >= 0)
    {
        if (i >= 0)
        {
            sum = sum + (num1[i] - 48);
            i--;
        }
        if (j >= 0)
        {
            sum = sum + (num2[j] - 48);
            j--;
        }
        carry = sum % 10 + 48;
        result = result + char(carry);
        sum = sum / 10;
    }

    reverse(result.begin(), result.end());

    cout << "SUM : " << result << endl;

    return 0;
}