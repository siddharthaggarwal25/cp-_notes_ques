#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        indegree[b]++;
        adj[a].push_back(b);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;

    while (!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();

        for (auto child : adj[node])
        {
            indegree[child]--;
            if (indegree[child] == 0)
            {
                q.push(child);
            }
        }
    }

    if (ans.size() != n)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}