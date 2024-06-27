#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(int x, int y, int z, int k)
{
    int ans = 0;
    for (int a= 1; a <= cbrt(k); a++)
    {
        if (k % a == 0)
        {
            for (int b = 1; b <= sqrt(k/a); b++)
            {
                if ((k / a) % b == 0)
                {
                    int c = k / (a * b);
                    if (a <= x && b <= y && c <= z)
                    {
                        ans = max(ans, (x - a + 1) * (y - b + 1) * (z - c + 1));
                    }
                    if (a <= x && c <= y && b <= z)
                    {
                        ans = max(ans, (x - a + 1) * (y - c + 1) * (z - b + 1));
                    }
                    if (b <= x && a <= y && c <= z)
                    {
                        ans = max(ans, (x - b + 1) * (y - a + 1) * (z - c + 1));
                    }
                    if (b <= x && c <= y && a <= z)
                    {
                        ans = max(ans, (x - b + 1) * (y - c + 1) * (z - a + 1));
                    }
                    if (c <= x && a <= y && b <= z)
                    {
                        ans = max(ans, (x - c + 1) * (y - a + 1) * (z - b + 1));
                    }
                    if (c <= x && b <= y && a <= z)
                    {
                        ans = max(ans, (x - c + 1) * (y - b + 1) * (z - a + 1));
                    }
                }
            }
        }
    }
    return ans;
}

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x, y, z , k ;
        cin >> x >> y >> z >> k;
        int ans = solve(x, y, z, k);
        cout << ans << endl;
    }

    return 0;
}
