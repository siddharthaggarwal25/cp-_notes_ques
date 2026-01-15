#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int s, k, m;
        cin >> s >> k >> m;

        if (s <= k)
        {
            cout << max(0, s - (m % k)) << endl;
        }
        else
        {
            int a = s;
            int b = k;
            int timeleft = m % k;
            int su = m / k;

            if (su % 2 == 0)
            {
                cout << a - timeleft << endl;
            }
            else
            {
                cout << b - timeleft << endl;
            }
        }
    }
    return 0;
}