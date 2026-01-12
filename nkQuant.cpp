#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, int c, vector<int> &s, vector<int> &e, vector<int> &w)
{
    c--;
    vector<vector<pair<int, int>>> adj(n);
    vector<int> dis(n, 1e9);

    for (int i = 0; i < s.size(); i++)
    {
        adj[s[i] - 1].push_back({e[i] - 1, w[i]});
        adj[e[i] - 1].push_back({s[i] - 1, w[i]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, c});
    dis[c] = 0;

    while (!pq.empty())
    {
        int node = pq.top().second;
        int curdis = pq.top().first;

        pq.pop();
        if (curdis > dis[node])
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

    vector<vector<int>> dag(n);
    for (int i= 0; i < n; i++)
    {
        for (auto j : adj[i])
        {
            int v1 = j.first;
            int tr = j.second;

            if (dis[i] + tr == dis[v1])
            {
                dag[i].push_back(v1);
            }
        }
    }

    vector<int> order(n);
    vector<set<int>> pred(n);

    iota(order.begin(), order.end(), 0);

    sort(order.begin(), order.end(),
         [&](int a, int b)
         {
             return dis[a] < dis[b];
         });

    for (int i : order)
    {
        for (int j : dag[i])
        {
            for (int x : pred[i])
            {
                pred[j].insert(x);
            }
            if (i != c)
            {
                pred[j].insert(i);
            }
        }
    }

    // ---------- Step 4: Build answer ----------
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        ans[i] = pred[i].size();
    }

    return ans;
}
int main()
{

    int graphnode = 6;
    int capital = 1;
    vector<int> graph_from = {3, 1, 4, 2, 5, 2, 2, 5};
    vector<int> graph_to = {6, 3, 6, 4, 3, 3, 1, 4};
    vector<int> graph_weight = {2, 2, 1, 1, 1, 2, 2, 1};

    vector<int> ans = solve(graphnode, capital, graph_from, graph_to, graph_weight);
    for (auto a : ans)
        cout << a << " ";

    return 0;
}