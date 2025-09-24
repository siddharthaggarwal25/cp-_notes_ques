// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// class DSU
// {
// public:
//     vector<int> par, s;
//     DSU(int n)
//     {
//         par.resize(n + 1);
//         s.resize(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             par[i] = i;
//             s[i] = 1;
//         }
//     }

//     int findparent(int x)
//     {
//         if (par[x] == x)
//             return x;
//         return par[x] = findparent(par[x]);
//     }

//     void unite(int a, int b)
//     {
//         int pa = findparent(a);
//         int pb = findparent(b);

//         if (pa == pb)
//             return;

//         if (s[pa] > s[pb])
//         {
//             s[pa] += s[pb];
//             par[pb] = pa;
//         }
//         else
//         {
//             s[pb] += s[pa];
//             par[pa] = pb;
//         }
//     }

//     bool check(int n)
//     {
//         for (int i = 1; i <= n; i++)
//         {
//             if (s[i] == n)
//                 return true;
//         }
//         return false;
//     }
// };
// int32_t main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<pair<int, pair<int, int>>> edges;
//     DSU dsu(n);
//     for (int i = 0; i < m; i++)
//     {
//         int u, v, cost;
//         cin >> u >> v >> cost;
//         edges.push_back({cost, {u, v}});
//     }
//     sort(edges.begin(), edges.end());
//     int ans = 0;
//     for (auto edge : edges)
//     {
//         int cost = edge.first;
//         int u = edge.second.first;
//         int v = edge.second.second;

//         if (dsu.findparent(u) != dsu.findparent(v))
//         {
//             ans += cost;
//             dsu.unite(u, v);
//         }
//     }
//     bool check = dsu.check(n);
//     if (check)
//     {
//         cout << ans << endl;
//     }
//     else
//     {
//         cout << "IMPOSSIBLE" << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> visited(n + 1, 0);
    pq.push({0, 1});
    int cost = 0;
    int cnt  =0  ;

    while (!pq.empty())
    {
        int w = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node])
            continue;

        cost += w;
        cnt++;
        visited[node] = 1;

        for (auto child : adj[node])
        {
            if (visited[child.first])
                continue;
            pq.push({child.second, child.first});
        }
    }

    if( cnt  == n)cout<<cost<<endl;
    else cout<<"IMPOSSIBLE"<<endl;

    // cout << ((cnt == n)  ? cost :  "IMPOSSIBLE" )<< endl;

    return 0;
}