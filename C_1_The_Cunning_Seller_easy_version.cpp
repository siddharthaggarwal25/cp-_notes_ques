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
        vector<int> power(20), coins(20);
        int val = 1;
        for (int i = 0; i < 20; i++)
        {
            power[i] = val;
            val = val * 3;
            coins[i] = power[i] * 3 + (i * (power[i] / 3));
        }
        int cost = 0;
        for (int i = 19; i >= 0; i--)
        {
            int times = n / power[i];
            n = n % power[i];
            cost += coins[i] * times;
        }
        cout << cost << endl;
    }
    return 0;
}