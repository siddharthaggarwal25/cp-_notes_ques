#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        vector<int> b, c;
        int cnt = 0;
        const int INF = 1e9 + 7;
        int x = INF, y = INF;
        int penalty = 0;
        for (auto ai : v)
        {

            if (x > y)
                swap(x, y);

            if (ai <= x)
            {

                x = ai;
            }
            else if (y < ai)
            {

                penalty++;
                x = ai;
            }
            else
            {

                y = ai;
            }
        }
        cout << penalty << endl;
    }
    return 0;
}