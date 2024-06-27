#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> vis, depth, par;
vector<vector<int>> up, min_edge;
const int LOG = 20;

void dfs(int node, int parent) {
    vis[node] = 1;
    par[node] = parent;
    up[node][0] = parent;

    for (int i = 1; i < LOG; i++) {
        up[node][i] = up[up[node][i - 1]][i - 1];
        min_edge[node][i] = min(min_edge[node][i - 1], min_edge[up[node][i - 1]][i - 1]);
    }

    for (auto &child : adj[node]) {
        if (vis[child.first]) continue;
        depth[child.first] = depth[node] + 1;
        min_edge[child.first][0] = child.second;
        dfs(child.first, node);
    }
}

int kthparent(int node, int k) {
    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)) {
            node = up[node][i];
        }
    }
    return node;
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    a = kthparent(a, depth[a] - depth[b]);
    if (a == b) return a;

    for (int i = LOG - 1; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

void update_min_edge(int& node, int lc, int& min_edge_value) {
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[node] - (1 << i) >= depth[lc]) {
            min_edge_value = min(min_edge_value, min_edge[node][i]);
            node = up[node][i];
        }
    }
}

int find_min_edge_in_path(int a, int b) {
    int min_edge_value = INT_MAX;
    int lc = lca(a, b);

    update_min_edge(a, lc, min_edge_value);
    update_min_edge(b, lc, min_edge_value);

    return min_edge_value;
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    vis.assign(n + 1, 0);
    depth.assign(n + 1, 0);
    up.assign(n + 1, vector<int>(LOG));
    min_edge.assign(n + 1, vector<int>(LOG, INT_MAX));
    par.assign(n + 1, -1);

    for (int i = 0; i <= n; i++) {
        up[i].assign(20, 0);
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs(1, 1);

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << find_min_edge_in_path(a, b) << endl;
    }

    return 0;
}
