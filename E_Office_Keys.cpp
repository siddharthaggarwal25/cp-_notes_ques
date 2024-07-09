#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> people(n), keys(m);
    for (int i = 0; i < n; i++)
        cin >> people[i];
    for (int i = 0; i < m; i++)
        cin >> keys[i];
    int ans = INT_MIN;
    vector<int> vis(m, 0);
    for (int i = 0; i < n; i++)
    {
        int ind;
        int val = INT_MAX;
        for (int j = 0; j < m; j++)
        {
            if (vis[j] == 0)
            {
                int cost = abs(keys[j] - people[i]) + abs(keys[j] - p);
                if (cost < val)
                {
                    val = cost;
                    ind = j;
                }
            }
        }
        ans = max( ans , val);
        vis[ind] = 1;
    }
    cout<<ans<<endl;
     return 0;
}
