#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, l, out = 0, count = 0;
    string str;
    getline(cin, str);
    l = str.length();
    for (i = 0; i < l; i++)
    {
        out = 0;
        if (str[i] == '(')
        {
            for (j = i; j < l; j++)
            {
                if (str[j] == '(')
                    out++;
                else if (str[j] == ')')
                    out--;
                if (out < 0)
                    break;
            }
            if (out >= 0)
            {
                for (j = 0; j < i; j++)
                {
                    if (str[j] == '(')
                        out++;
                    else if (str[j] == ')')
                        out--;
                    if (out < 0)
                        break;
                }
                if (out == 0)
                    count++;
            }
        }
    }
    cout << count;

    return 0;
}