#include <bits/stdc++.h>
using namespace std;

int dij(int start, int end, int n, int l, vector<vector<pair<int, int>>> &adj)
{
    priority_queue < array <int , 3> , vector<array<int , 3>>  greater<array<int , 3>> > pq;
    int cost[n+1][n+1]  //to reach i th index, how much times i have refule , and f=gives cruurent fuel value   ;
    memset( cost , -1 , sizeof( cost));
    cost[start][0] = l;
    pq.push({l, {start, 0 }});
    while (!pq.empty())
    {
        auto [currcost, state] = pq.top();
        auto [node, currfuel] = state;
        pq.pop();

        if (cost[node][currfuel] < currcost)
            continue;

        for (auto [next, weight] : adj[node])
        {
            if (currfuel >= weight && cost[next][currfuel - weight] > currcost)
            {
                cost[next][currfuel - weight] = currcost;
                pq.push({currcost, {next, currfuel - weight}});
            }
            if (cost[next][l - weight] > currcost + 1)
            {
                cost[next][l - weight] = currcost + 1;
                pq.push({currcost + 1, {next, l - weight}});
            }
        }
    }

    int ans = *min_element(cost[end].begin(), cost[end].end());
    return (ans == 1e9) ? -1 : ans;
}

int main()
{
    int n, m, l;
    cin >> n >> m >> l;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int s, e;
        cin >> s >> e;
        cout << dij(s, e, n, l, adj) << endl;
    }

    return 0;
}
