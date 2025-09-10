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
        string s;
        cin >> s;
        int ans = 0;
        int cnt = 0;
        bool temp = false;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '#')
            {
                ans += cnt;
                cnt = 0;
            }
            else
            {
                cnt++;
                if (cnt > 2)
                {
                    temp = true;
                }
            }
        }
        ans += cnt;
        if (temp)
            cout << 2 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}