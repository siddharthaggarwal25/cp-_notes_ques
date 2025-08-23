#include <bits/stdc++.h>
using namespace std;

vector<int> dfs(int node, int parent, vector<int> &par, vector<int> &vis, vector<vector<int>> &adj)
{
	vis[node] = 1;
	par[node] = parent;

	for (int child : adj[node])
	{
		if (child == parent)
			continue;

		if (vis[child] == -1)
		{
			auto cycle = dfs(child, node, par, vis, adj);
			if (!cycle.empty())
				return cycle;
		}
		else
		{
			vector<int> cycle;
			cycle.push_back(child);
			for (int v = node; v != child; v = par[v])
			{
				cycle.push_back(v);
			}
			cycle.push_back(child);
			reverse(cycle.begin(), cycle.end());
			return cycle;
		}
	}
	return {};
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if(m<n  ){
		cout << "IMPOSSIBLE\n";
		return 0 ;
	}
	vector<int> vis(n + 1, -1), par(n + 1, -1);

	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == -1)
		{
			auto cycle = dfs(i, -1, par, vis, adj);
			if (!cycle.empty())
			{
				cout << cycle.size() << "\n";
				for (int v : cycle)
					cout << v << " ";
				cout << "\n";
				return 0;
			}
		}
	}

	return 0;
}
