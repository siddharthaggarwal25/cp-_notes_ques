#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            maxi = max(maxi, x);
        }

        while (m--)
        {
            char c;
            int a, b, ma, mi;
            cin >> c >> a >> b;
            mi = min(a, b);
            ma = max(a, b);
            if (c == '+')
            {
                if (maxi >= mi && maxi <= ma)
                {
                    maxi++;
                }
            }
            else
            {
                if (maxi >= mi && maxi <= ma)
                {
                    maxi--;
                }
            }
            cout << maxi << " ";
        }
        cout<<endl;
    }
    return 0;
}