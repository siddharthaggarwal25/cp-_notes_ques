#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

vector<vector<int>> adj;
vector<int> dist1, distn;


vector<int> bfs(int src, int n) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

bool cmp(int a, int b) {
    return (dist1[a] - distn[a]) < (dist1[b] - distn[b]);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> special(k);
    for (int i = 0; i < k; i++) cin >> special[i];

    adj.assign(n + 1, {});

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dist1 = bfs(1, n);
    distn = bfs(n, n);

    int base = dist1[n];    

    sort(special.begin(), special.end(), cmp);

    int best = 0;
    int pref_max = -INF;

    for (int v : special) {
        if (pref_max != -INF) {
            best = max(best, pref_max + distn[v]);
        }
        pref_max = max(pref_max, dist1[v]);
    }

    cout << min(base, best + 1) << "\n";

    return 0;
}
