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
        string s;
        cin >> s;
        map<int, int> mp;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }
        int ind = 1;

        if (s[0] == 'A')
        {
            ind++;
            mp[ind] = 1;
        }
        else
        {
            if(mp.find( 1) == mp.end())ind++;
            while (mp.find(ind) != mp.end())
            {
                ind++;
            }
            mp[ind] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] == 'A' && s[i] == 'A')
            {
                ind = ind + 1;
                mp[ind] = 1;
            }
            else if (s[i - 1] == 'A' && s[i] == 'B')
            {
                while (mp.find(ind) != mp.end())
                {
                    ind++;
                }
                mp[ind] = 1;
            }
            else if (s[i - 1] == 'B' && s[i] == 'A')
            {
                while (mp.find(ind) != mp.end())
                {
                    ind++;
                }
                ind++;
                mp[ind] = 1;
            }
            else
            {
                while (mp.find(ind) != mp.end())
                {
                    ind++;
                }
                ind++;
                while (mp.find(ind) != mp.end())
                {
                    ind++;
                }
                mp[ind] = 1;
            }
        }
        cout << mp.size() << endl;
        for (auto it : mp)
        {
            cout << it.first << " ";
        }
        cout << endl;
    }
    return 0;
}