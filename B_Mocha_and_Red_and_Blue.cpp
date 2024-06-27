#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int first = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'B' || s[i] == 'R')
            {
                first = i;
                break;
            }
        }
        if (first == -1)
        {
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                {
                    cout << 'R';
                }
                else
                {
                    cout << 'B';
                }
            }
            cout << endl;
        }
        else
        {
            char current;
            for (int i = first; i < n; i++)
            {
                if (s[i] != '?')
                {
                    current = s[i];
                }
                else
                {
                    if (current == 'B')
                    {
                        s[i] = 'R';
                        current = 'R';
                    }
                    else
                    {
                        s[i] = 'B';
                        current = 'B';
                    }
                }
            }
            for (int i = first; i >= 0; i--)
            {
                if (s[i] != '?')
                {
                    current = s[i];
                }
                else
                {
                    if (current == 'B')
                    {
                        s[i] = 'R';
                        current = 'R';
                    }
                    else
                    {
                        s[i] = 'B';
                        current = 'B';
                    }
                }
            }
            cout << s << endl;
        }
    }
    return 0;
}