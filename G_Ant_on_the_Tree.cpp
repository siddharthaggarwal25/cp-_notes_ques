#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> par;
vector<int> sz;
vector<int> ans;
deque<int> temp;
vector<int > depth;
void dfs(int node, int parent)
{

    depth[node] = depth[parent]+1;
    par[node] = parent;
    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        dfs(child, node);
        sz[node] += sz[child];
    }
}

int lca(int a, int b)
{
    if (depth[b] > depth[a])
        swap(a, b);
    while (depth[a] != depth[b])
    {
        a = par[a];
    }
    while (par[a] != par[b])
    {
        a = par[a];
        b = par[b];
    }
    return par[a];
}

void connectPath(int a, int b, int c)
{
    temp.clear();
    int flag = b;
    while (a != flag)
    {
        temp.push_front(flag);
        flag = par[flag];
    }
    flag = b;
    temp.push_front(a);
    temp.pop_back();

    while (c != flag)
    {
        temp.push_back(flag);
        flag = par[flag];
    }
    for (int z = 0; z < temp.size(); z++)
    {
        ans.push_back(temp[z]);
    }
}
int main()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    sz.assign(n + 1, 1);
    par.assign(n + 1, 0);
    depth.assign( n+1 , 0 );
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        if (sz[i] == 1)
            k++;
    }
    vector<int> path(k);
    for (int i = 0; i < k; i++)
    {
        cin >> path[i];
    }
    vector<int> must;
    must.push_back(1);
    for (int i = 0; i < k - 1; i++)
    {
        must.push_back(path[i]);
        must.push_back(lca(path[i], path[i + 1]));
    }
    must.push_back(path[k - 1]);
    must.push_back(1);
    for (int i = 0; i < must.size() - 2; i = i + 2)
    {
        connectPath(must[i], must[i + 1], must[i + 2]);
    }
    ans.push_back(1);
    if (ans.size() == (2 * n - 1))
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}