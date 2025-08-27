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
      int a, b, c;
      cin >> a >> b >> c;
      adj[a].push_back({b, c});
   }
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   vector<int> dis(n + 1, 1e16);
   pq.push({0, 1});
   dis[1] = 0;
   while (!pq.empty())
   {
      int curdis = pq.top().first;
      int node = pq.top().second;
      pq.pop();

      if (dis[node] < curdis)
         continue;
      for (auto child : adj[node])
      {
         if (dis[child.first] > curdis + child.second)
         {
            dis[child.first] = curdis + child.second;
            pq.push({curdis + child.second, child.first});
         }
      }
   }
   for (int i = 1; i <= n; i++)
      cout << dis[i] << " ";

   return 0;
}