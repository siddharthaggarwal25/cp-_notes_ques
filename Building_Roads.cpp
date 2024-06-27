#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis)
{
  vis[node] = 1;
  for (auto child : adj[node])
  {
    if (vis[child])
      continue;
    dfs(child, adj, vis);
  }
}
int main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  vector<int> vis(n + 1, 0);
  vector<int> ans;
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++)
  {
    if (!vis[i])
    {
      dfs(i, adj, vis);
      ans.push_back(i);
      cnt++;
    }
  }
  cnt--;
  cout << cnt << endl;
  for (int i = 0; i < cnt; i++)
  {
    cout << ans[i] << " " << ans[i + 1] << endl;
  }

  return 0;
}
