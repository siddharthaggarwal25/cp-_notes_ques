#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    int ans = 0;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int x;
            cin >> x;
            adj[x].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> topo;
    while (!q.empty())
    {
        queue<int> temp;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto child : adj[node])
            {
                indegree[child]--;
                if (indegree[child] == 0)
                {
                    if (child > node)
                        q.push(child);
                    else
                        temp.push(child);
                }
            }
        }
        while (!temp.empty())
        {
            q.push(temp.front());
            temp.pop();
        }
        ans++;
    }
    if (topo.size() != n)
        cout << -1 << endl;
    else
    {
        cout << ans << endl;
    }

    return 0;
}