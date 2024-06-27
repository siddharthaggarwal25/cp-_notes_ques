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
        vector<int> v(n);
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            s.insert(v[i]);
        }
        if (s.size() == 1)
        {
            cout << -1 << endl;
        }
        else
        {
            int count = 0;
            int ans = INT_MAX;
            int el = v[0];
            for (int i = 0; i < n; i++)
            {
                count = 0;
                bool flag = false;
                while (el == v[i] && i < n)
                {
                    count++;
                    i++;
                    flag = true;
                }
                if (flag)
                    ans = min(ans, count);
            }
            cout << ans << endl;
        }
    }
    return 0;
}