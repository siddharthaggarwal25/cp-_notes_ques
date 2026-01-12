#include <bits/stdc++.h>
using namespace std;

// ----------------------------------------------------------
// Helper: BFS returning (farthest-node, distance) from src
pair<int,int> bfs(int src, const vector<vector<int>>& g) {
    int n = g.size();
    vector<int> dist(n, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    int best = src;
    for (int i = 0; i < n; ++i)
        if (dist[i] > dist[best]) best = i;
    return {best, dist[best]};
}

// ----------------------------------------------------------
// Core function: minimize diameter after ≤ k leaf removals
int treecut(int n, int k, vector<vector<int>> edges) {
    if (n <= 1) return 0;

    // build adjacency
    vector<vector<int>> g(n+1);
    for (auto &e : edges) {
        int u = e[0], v = e[1];
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // find endpoints of longest path (u--v)
    auto [u, _1] = bfs(1, g);
    auto [v, diam] = bfs(u, g);

    // if we can completely erase the longest path, do it
    if (k >= diam) return 0;

    // otherwise the best we can do is diam - k
    return diam - k;
}

// ----------------------------------------------------------
// Main with the three given test-cases
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ---- Sample 0 (n=3, k=0) ----
    {
        int n = 3, k = 0;
        vector<vector<int>> edges = {{1,2},{1,3}};
        cout << treecut(n, k, edges) << '\n'; // expected 2
    }

    // ---- Sample 1 (n=5, k=1) ----
    {
        int n = 5, k = 1;
        vector<vector<int>> edges = {{1,2},{1,3},{1,4},{3,5}};
        cout << treecut(n, k, edges) << '\n'; // expected 2
    }

    // ---- Sample 2 (n=5, k=2) ----
    {
        int n = 5, k = 2;
        vector<vector<int>> edges = {{1,2},{1,4},{2,3},{2,5}};
        cout << treecut(n, k, edges) << '\n'; // expected 1
    }

    return 0;
}