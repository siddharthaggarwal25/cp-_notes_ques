#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int ans = 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int mini = v[0], maxi = v[0];

        for (int i = 0; i < n; i++)
        {

            mini = min(mini, v[i]);
            maxi = max(maxi, v[i]);
            int diff = maxi - mini;
            if (diff  2 * x)
            {
                ans++;
                mini = v[i];
                maxi = v[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}