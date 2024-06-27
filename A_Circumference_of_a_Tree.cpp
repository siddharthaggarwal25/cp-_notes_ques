#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &dis)
{
    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        dis[child] = 1 + dis[ node ];
        dfs(child, node, adj, dis);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> dis(n + 1, 0);
    dfs(1, 1, adj, dis);
    int firstEnd = max_element( dis.begin() , dis.end()) - dis.begin();
    dis.assign(n + 1, 0);
    dfs(firstEnd, firstEnd, adj, dis);
    int dia  = *max_element ( dis.begin() , dis.end());
    cout << 3*dia << endl;

    return 0;
}