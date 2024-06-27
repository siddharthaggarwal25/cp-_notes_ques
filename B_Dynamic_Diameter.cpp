#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &dis)
{
    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        dis[child] = dis[node] + 1;
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
    int maxdis = *max_element(dis.begin(), dis.end());
    int firstNode = max_element(dis.begin(), dis.end()) - dis.begin();
    set<int> temp;
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] == maxdis)
        {
            temp.insert(i);
        }
    }
    vector<int> dis2(n + 1, 0);
    dfs(firstNode, firstNode, adj, dis2);
    maxdis = *max_element(dis2.begin(), dis2.end());
    for (int i = 1; i <= n; i++)
    {
        if (dis2[i] == maxdis)
        {
            temp.insert(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (temp.find(i) != temp.end())
        {
            cout << maxdis + 1 << endl;
        }
        else
        {
            cout << maxdis << endl;
        }
    }
    return 0;
}