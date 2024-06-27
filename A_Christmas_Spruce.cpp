#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> adj;
vector<bool> isParent;
int32_t main()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    isParent.assign(n + 1, false);
    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        adj[a].push_back(i);
        isParent[a] = true;
    }
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        int s = adj[i].size();
        int z = s;
        for (int j = 0; j < z; j++)
        {
            if (isParent[adj[i][j]])
                s--;
        }
        if (isParent[i] && (s < 3))
        {
            flag = false;
        }
    }
    if (flag)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}