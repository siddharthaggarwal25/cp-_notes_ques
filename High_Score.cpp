#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, long long>> edges;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({{a, b}, -1LL * c});
    }

    vector<long long> dis(n + 1, 1e18);
    dis[1] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (auto edge : edges) {
            int u = edge.first.first;
            int v = edge.first.second;
            long long w = edge.second;
            if (dis[u] != 1e18 && dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
            }
        }
    }

    bool check = false;
    for (auto edge : edges) {
        int u = edge.first.first;
        int v = edge.first.second;
        long long w = edge.second;
        if (dis[u] != 1e18 && dis[v] > dis[u] + w) {
            check = true;
        }
    }

    if (check) {
        cout << -1 << endl;
    } else {
        cout << -dis[n] << endl;
    }

    return 0;
}
