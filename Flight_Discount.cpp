#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int n, m;
   cin >> n >> m;
   vector<vector<pair<int, int>>> adj(n + 1);
   for (int i = 0; i < m; i++)
   {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].push_back({v, w});
   }

   vector<vector<int>> dis(n + 1, vector<int>(2, 1e16));
   priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
   dis[1][0] = 0;
   pq.push({0, 1, 0});

   while (!pq.empty())
   {
      auto [curdis, node, isUsed] = pq.top();
      pq.pop();

      if (dis[node][isUsed] < curdis)
         continue;

      for (auto child : adj[node])
      {
         if (isUsed == 1)
         {
            if (dis[child.first][1] > curdis + child.second)
            {
               dis[child.first][1] = curdis + child.second;
               pq.push({curdis + child.second, child.first, 1});
            }
         }

         if (isUsed == 0)
         {
            if (dis[child.first][1] > curdis + (child.second / 2))
            {
               dis[child.first][1] = curdis + (child.second / 2);
               pq.push({curdis + (child.second / 2), child.first, 1});
            }
            if (dis[child.first][0] > curdis + child.second)
            {
               dis[child.first][0] = curdis + child.second;
               pq.push({curdis + child.second, child.first, 0});
            }
         }
      }
   }

   cout << dis[n][1] << endl;

   return 0;
}