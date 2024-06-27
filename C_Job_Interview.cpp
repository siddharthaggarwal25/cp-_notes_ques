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
        vector<int> a(n + m + 1);
        vector<int> b(n + m + 1);
        for (int i = 0; i < n + m + 1; i++)
            cin >> a[i];
        for (int i = 0; i < n + m + 1; i++)
            cin >> b[i];

        for (int i = 0; i < n + m + 1; i++)
        {
            int x = n;
            int y = m;
            int ans = 0;
            for (int j = 0; j < n + m + 1; j++)
            {
                if (i != j)
                {
                    if (x > 0 && y > 0)
                    {
                        if (a[j] > b[j])
                        {
                            x--;
                            ans += a[j];
                        }
                        else
                        {
                            y--;
                            ans += b[j];
                        }
                    }
                    else if (x > 0)
                    {
                        x--;
                        ans += a[j];
                    }
                    else
                    {
                        y--;
                        ans += b[j];
                    }
                }
            }
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}