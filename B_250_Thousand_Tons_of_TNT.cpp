#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(vector<int> &v, int num)
{
    int mini = 1e18;
    int maxi = 0;
    for (int i = 0; i < v.size(); i += num)
    {
        int temp = 0;
        for (int j = 0; j < num; j++)
        {
            temp += v[i + j];  
        }
        maxi = max(maxi, temp);
        mini = min(mini, temp);
    }
    return maxi - mini;
}

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

        int ans = 0;
        for (int i = 1; i * i <= n; i++) 
        {
            if (n % i == 0)
            {
                int val1 = solve(v, i);
                int val2 = solve(v, n / i);
                ans = max(ans, max(val1, val2));
            }
        }

        cout << ans << endl;
    }
    return 0;
}
