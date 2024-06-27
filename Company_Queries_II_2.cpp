#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> parent;
void dfs(int node, int par)
{
    parent[node] = par;
    for (auto child : adj[node])
    {
        dfs(child, node);
    }
}
int main()
{
    int n, q;
    cin >> n >> q;
    adj.resize(n + 1);
    parent.resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        adj[a].push_back(i);
    }
    parent[1] = 0;
    dfs(1, 0);
    while (q--)
    {
        vector<int> path1;
        vector<int> path2;
        int a, b;
        cin >> a >> b;
        while (a != 0)
        {
            path1.push_back(a);
            a = parent[a];
        }
        while (b != 0)
        {
            path2.push_back(b);
            b = parent[b];
        }
        // for (int i = 0; i < path1.size(); i++)
        // {
        //     cout << path1[i] << " ";
        // }
        // cout << endl;
        // for (int i = 0; i < path2.size(); i++)
        // {
        //     cout << path2[i] << " ";
        // }
        // cout << endl;
        int i = 0;
        int j = 0;
        while (path1[i] != path2[j])
        {
            if (path1[i] > path2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        cout<<path1[i]<<endl;
    }

    return 0;
}