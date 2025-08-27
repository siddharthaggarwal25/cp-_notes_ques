#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        if (a > b)
            swap(a, b);

        int cnt = 0;
        while (true)
        {
            if (a * 8 <= b)
            {
                cnt++;
                a = a * 8;
            }
            else if (a * 4 <= b)
            {
                cnt++;
                a = a * 4;
            }
            else if (a * 2 <= b)
            {
                cnt++;
                a = a * 2;
            }
            else
            {
                break;
            }
        }
        if (a == b)
        {
            cout << cnt << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}