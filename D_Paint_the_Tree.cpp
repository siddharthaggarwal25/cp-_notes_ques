#include <bits/stdc++.h>
using namespace std;
vector<int> order;

void dfs(int node, int par, vector<vector<int>>& adj) {
    for (auto child : adj[node]) {
        if (child == par) continue;
        dfs(child, node, adj);
    }
    order.push_back(node);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n + 1, vector<int>(3, 0));
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[j][i];
        }
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        if (adj[x].size() > 2 || adj[y].size() > 2) {
            cout << -1 << endl;
            return 0;
        }
    }
    int start = 0;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            start = i;
            break;
        }
    }
    dfs(start, 0, adj);
    vector<int> ans(n + 1);
    long long cost = LLONG_MAX;
    int m[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
    for (int i = 0; i < 6; i++) {
        long long val = 0;
        int j = 0;
        vector<int> temp(n + 1);
        for (auto x : order) {
            val += arr[x][m[i][j]];
            temp[x] = m[i][j] + 1;
            j = (j + 1) % 3;
        }
        if (val < cost) {
            cost = val;
            ans = temp;
        }
    }
    cout << cost << endl;
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
