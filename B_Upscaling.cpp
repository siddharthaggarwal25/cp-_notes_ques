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
        char start = '#';
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < 2; k++)
            {
                if (i % 2 == 0)
                {
                    start = '#';
                }
                else
                {
                    start = '.';
                }
                char now = start;
                for (int j = 0; j < n; j++)
                {
                    cout << now << now;
                    if (now == '#')
                    {
                        now = '.';
                    }
                    else
                    {
                        now = '#';
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}