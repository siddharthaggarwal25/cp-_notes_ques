#include <bits/stdc++.h>

using namespace std;
vector<vector<pair<int, int>>> adj;
#define int long long
int32_t main()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n+1);
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    map<pair<int, int>, int> mp;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int t;
            cin >> t;
            mp[{i, t}] = 1;
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(n + 1, 1e9);               
    pq.push({0, 1});
    dis[1] = 0;
    while (!pq.empty())
    {
        int nodedis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(dis[node]< nodedis)continue;
		if(node==n)
		{
			cout<<nodedis<<endl;
			return 0;
		}

        while (mp[{node, nodedis}])
        {
            nodedis++;
        }

        for (auto child : adj[node])
        {
            if (dis[child.first] > nodedis + child.second)
            {
                dis[child.first] = nodedis + child.second;
                pq.push({dis[child.first], child.first});
            }
        }
    }
    if (dis[n] == 1e9)
        cout << -1 << endl;
    else
    {
        cout << dis[n] << endl;
    }

    return 0;
}