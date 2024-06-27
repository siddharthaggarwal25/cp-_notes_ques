#include <bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<pair<int, int>>> adj(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    for (int i = 0; i < k; i++) {
        int v, w;
        cin >> v >> w;
        adj[1].push_back({v, w});
        adj[v].push_back({1, w});
    }
    
    vector<int> dist(n + 1, 1e18);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
   for( int i=1  ;i<=n  ;i++ ) cout<<dist[i] <<" ";
    
    // cout << k - cnt << '\n';
    
    return 0;
}
