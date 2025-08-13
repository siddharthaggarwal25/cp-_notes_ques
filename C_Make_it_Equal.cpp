#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        map<int, int> mp;
        int n, k;
        cin >> n >> k;
        bool ans = true;
        vector<int> s(n), t(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            s[i] = s[i] % k;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> t[i];
            t[i] = t[i] % k;
            mp[t[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (mp[s[i]] != 0)
            {
                mp[s[i]]--;
            }
            else
            {
                if (mp[abs(k - s[i])] != 0)
                    mp[abs(k - s[i])]--;
                else
                    ans = false;
            }
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}