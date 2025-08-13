#include <bits/stdc++.h>
using namespace std;
#define int long long
int solve(vector<int> &v, int t)
{
    set<int> s;
    for (int i = 0; i < v.size(); i++)
        s.insert(v[i] % t);
    return s.size();
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int ans = 2;
        while (true)
        {
            int temp = solve(v, ans);
            if (temp == 2)
            {
                cout << ans << endl;
                break;
            }
            ans = ans * 2;
        }
    }
    return 0;
}