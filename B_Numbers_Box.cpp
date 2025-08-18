#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> v(n * m);
        int cnt = 0;
        int ans = 0;
        int mini = 1e9;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                mini = min(mini, abs(x));
                if (x <= 0)
                    cnt++;
                ans += abs(x);
            }
        if (cnt % 2 == 0)
            cout << ans << endl;
        else
            cout << ans - 2 * mini << endl;
    }
    return 0;
}