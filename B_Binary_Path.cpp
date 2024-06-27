#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        string s = "";
        s += s1[0];
        int j = -1, k = n - 1, f = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (f == 0)
            {
                if (s1[i + 1] == s2[i])
                {
                    s += s1[i + 1];
                }
                else if (s1[i + 1] == '0' && s2[i] == '1')
                {
                    j = i;
                    s += '0';
                }
                else
                {
                    k = i;
                    s += '0';
                    f = 1;
                }
            }
            else
                s += s2[i];
        }
        s += s2[n - 1];

        cout << s << '\n'
             << k - j << '\n';
    }
    return 0;
}