#include <bits/stdc++.h>
using namespace std;
#define int long long 
vector<vector<int>> adj;
vector<int> depth;
vector<int> par;
void dfs(int node, int parent)
{
    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        depth[child] = 1 + depth[node];
        dfs(child, node);
    }
}
void dfs2(int node, int parent)
{
    par[node] = parent;
    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        depth[child] = 1 + depth[node];
        dfs2(child, node);
    }
}
int32_t  main()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    };
    depth.assign(n + 1, 0);
    dfs(1, 1);
    int firstEnd = max_element(depth.begin(), depth.end()) - depth.begin();
    depth.assign(n + 1, 0);
    par.resize(n + 1);
    dfs2(firstEnd, 0);
    int secondEnd = max_element(depth.begin(), depth.end()) - depth.begin();
    int max = *max_element(depth.begin(), depth.end());
    vector<int> path;
    int two = secondEnd;
    while (secondEnd != firstEnd)
    {
        path.push_back(secondEnd);
        secondEnd = par[secondEnd];
    }
    path.push_back(firstEnd);

    vector<int> vis(n + 1, 0);
    vector<int> dis(n + 1, 0);
    queue<int> q;
    for (auto i : path)
    {
        dis[i] = 0;
        q.push(i);
        vis[i] = 1;
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto child : adj[node])
        {
            if (!vis[child])
            {
                q.push(child);
                dis[child] = dis[node] + 1;
                vis[child] = 1;
            }
        }
    }

    int maxnode = max_element(dis.begin(), dis.end()) - dis.begin();
    int val = *max_element(dis.begin(), dis.end());
    cout<<max +  val<<endl;
    cout << firstEnd << " " << two << " " << maxnode << endl;

    return 0;
}