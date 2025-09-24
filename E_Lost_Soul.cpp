#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        int ans = 0;
        map<int, int> mp;

        for (int i = n - 1; i >= 0; i--)
        {

            if (a[i] == b[i])
            {
                ans = i + 1;
                break;
            }

            if (mp.find(a[i]) == mp.end())
            {
                mp[a[i]] = i;
            }
            else
            {
                int ind = mp[a[i]];

                if (ind != i + 1)
                {
                    ans = i + 1;
                    break;
                }
                else
                {
                    if (a[i + 1] == a[i])
                    {
                        ans = i + 1;
                        break;
                    }
                }
            }

            if (mp.find(b[i]) == mp.end())
            {
                mp[b[i]] = i;
            }
            else
            {
                int ind = mp[b[i]];
                if (ind != i + 1)
                {
                    ans = i + 1;
                    break;
                }
                else
                {
                    if (b[i + 1] == b[i])
                    {
                        ans = i + 1;
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}