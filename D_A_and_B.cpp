#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(int n, string s, char x)
{
    vector<int> prefix(n), suffix(n);

    int cnt = 0;
    int val = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == x)
        {
            prefix[i] = val;
            cnt++;
        }
        else
        {
            val += cnt;
            prefix[i] = val;
        }
    }

    cnt = 0;
    val = 0;

    for (int i = n - 1; i >= 0; i--)
    {

        if (s[i] == x)
        {
            suffix[i] = val;
            cnt++;
        }
        else
        {
            val += cnt;
            suffix[i] = val;
        }
    }

    int ans = 1e18;
    for (int i = 0; i < n ; i++)
    {
        ans = min(ans, prefix[i] + suffix[i ]);
    }
    // ans = min(ans, prefix[n - 1]); 
    // ans = min(ans, suffix[0]);

    return ans;
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        int ans = min(solve(n, s, 'a'), solve(n, s, 'b'));
        cout << ans << endl;
    }
    return 0;
}