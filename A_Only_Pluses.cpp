#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()

{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        for (int i = 0; i <= 5; i++)
        {
            for (int j = 0; j <= 5; j++)
            {
                for (int k = 0; k <= 5; k++)
                {
                    if ((i + j + k) == 5)
                    {
                        int val = (a + i) * (b + j) * (c + k);
                        ans = max(ans, val);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}