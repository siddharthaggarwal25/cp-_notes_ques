#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, d, h;
    cin >> n >> d >> h;
    int longest = h;
    int second = d - h;

    if (d > 2 * h || d < h || (d == 1 && n > 2))
    {
        cout << -1 << endl;
        return 0;
    }
    int left = n - d - 1;
    int val = 1;
    for (int i = 1; i <= longest; i++)
    {
        cout << val << " " << ++val << endl;
    }
    for (int i = 1; i <= second; i++)
    {
        if (i == 1)
        {
            cout << 1 << " " << ++val << endl;
        }
        else
        {
            cout << val << " " << ++val << endl;
        }
    }
    if (h != d)
    {
        for (int i = 1; i <= left; i++)
        {
            cout << 1 << " " << ++val << endl;
        }
    }else {
         for (int i = 1; i <= left; i++)
        {
            cout << 2 << " " << ++val << endl;
        }

    }

    return 0;
}