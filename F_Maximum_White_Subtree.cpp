#include <bits/stdc++.h>
using namespace std;

vector<int> color;
vector<int> maxi;
vector<int> ans;
vector<vector<int>> adj;

int dfs(int node, int par) {
    for (auto child : adj[node]) {
        if (child == par)
            continue;

        int val = dfs(child, node);
        maxi[node] += val;
    }
    if (color[node] == 1)
        maxi[node]++;
    else
        maxi[node]--;
    return max(0, maxi[node]);
}

void rerooting(int node, int par) {
    ans[node] = maxi[node];
    for (auto child : adj[node]) {
        if (child == par)
            continue;

        maxi[node] -= max(0, maxi[child]);
        maxi[child] += max(0, maxi[node]);
        rerooting(child, node);
        maxi[child] -= max(0, maxi[node]);
        maxi[node] += max(0, maxi[child]);
    }
}

int main() {
    int n;
    cin >> n;
    adj.resize(n + 1);
    color.resize(n + 1);
    ans.resize(n + 1);
    maxi.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, -1);
    rerooting(1, -1);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}
