#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int tobuy, maxDeals;
        cin >> tobuy >> maxDeals;

        vector<int> watermelons(20), coins(20);
        int val = 1;
        for (int i = 0; i < 20; i++)
        {
            watermelons[i] = val;
            coins[i] = watermelons[i] * 3   + ( i*watermelons[i]/3);
            val *= 3;
        }

        int n = tobuy;
        vector<int> deals(20, 0);

        for (int i = 19; i >= 0; i--)
        {
            int times = n / watermelons[i];
            n %= watermelons[i];
            deals[i] += times;
        }

        int mindeals = 0;
        for (int i = 0; i < 20; i++)
            mindeals += deals[i];

        if (mindeals > maxDeals)
        {
            cout << -1 << endl;
        }
        else
        {
            int k = maxDeals - mindeals;

            for (int i = 19; i > 0 && k > 0; i--)
            {
                int maxSplits = min(deals[i], k / 2);
                deals[i] -= maxSplits;
                deals[i - 1] += maxSplits * 3;
                k -= maxSplits * 2;
            }

            int cost = 0;
            for (int i = 0; i < 20; i++)
                cost += deals[i] * coins[i];

            cout << cost << endl;
        }
    }
    return 0;
}
