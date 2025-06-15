#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(n, 1e18);
    vector<int> par(n);
    for (int i = 0; i < n; i++)
        par[i] = i;
    dis[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        for (auto it : adj[node])
        {
            if (dis[it.first] > cost + it.second)
            {
                dis[it.first] = cost + it.second;
                pq.push({dis[it.first], it.first});
                par[it.first] = node;
            }
        }
    }

    if (dis[n - 1] == 1e18)
        cout << -1 << endl;
    else
    {
        stack<int > st ;
        int ind  = n-1 ;
        while( ind != 0){
            st.push( ind);
            ind  = par[ind];
        }
        cout<<1<<" ";
        while( !st.empty()){
            cout<<st.top() +1<<" ";
            st.pop();
        }
        cout<<endl;
    }

    return 0;
}