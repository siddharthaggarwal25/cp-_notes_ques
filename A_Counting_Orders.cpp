#include <bits/stdc++.h>
#define int long long 
using namespace std;
int mod=1e9+7;
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool check = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < b[i])
            {
                check = false;
                break;
            }
        }

        int ans = 1;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            int value = a[i];
            while (b[j] < a[i] && j < n)
            {
                j++;
            }
            
            if (i > j)
            {
                check = false;
                break;
            }
            ans = ans * (j - i) % mod;
        }

       
        if (!check)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}