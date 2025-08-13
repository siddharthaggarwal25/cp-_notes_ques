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
        vector<pair<int, int>> v(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i].first;
            v[i].second = i;
        }

        sort(v.begin() + 1, v.end(), greater<>());

        vector<int> ans(n + 1);
        ans[0] = 0;

        int cost = 0;
        int pos = 1;
        int flag = 1;
        for (int i = 1; i <= n; i++)
        {
            if (flag == 1)
            {
                cost = cost + 2 * v[i].first * pos;
                ans[v[i].second] = pos;
                pos = pos * -1;
                flag = 0;
            }
            else
            {
                cost = cost - 2 * v[i].first * pos;
                ans[v[i].second] = pos;
                pos = pos * -1;
                pos++;
                flag = 1;
            }
        }

        cout << cost << endl;
        for( auto it : ans )cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}