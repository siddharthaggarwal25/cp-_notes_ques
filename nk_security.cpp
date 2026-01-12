#include <bits/stdc++.h>
using namespace std;

vector<int> getNeuronStrengths(int neuron_nodes,
                               vector<int> neuron_from,
                               vector<int> neuron_to,
                               vector<int> strongConnectivity) {
    int n = neuron_nodes;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < (int)neuron_from.size(); ++i) {
        int u = neuron_from[i];
        int v = neuron_to[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<long long> val(n + 1);
    for (int i = 1; i <= n; ++i) {
        val[i] = (strongConnectivity[i - 1] == 1) ? 1 : -1;
    }

    vector<long long> dp1(n + 1), up(n + 1), sumPos(n + 1);
    vector<int> parent(n + 1, 0);

    
    {
        vector<int> order;
        order.reserve(n);
        stack<int> st;
        st.push(1);
        parent[1] = 0;

        
        while (!st.empty()) {
            int v = st.top(); st.pop();
            order.push_back(v);
            for (int u : adj[v]) {
                if (u == parent[v]) continue;
                parent[u] = v;
                st.push(u);
            }
        }

       
        for (int idx = (int)order.size() - 1; idx >= 0; --idx) {
            int v = order[idx];
            long long s = 0;
            for (int u : adj[v]) {
                if (u == parent[v]) continue;
                if (dp1[u] > 0) s += dp1[u];
            }
            sumPos[v] = s;
            dp1[v] = val[v] + s;
        }
    }

    
    {
        vector<int> st;
        st.reserve(n);
        st.push_back(1);
        up[1] = 0;

        while (!st.empty()) {
            int v = st.back(); st.pop_back();
            for (int u : adj[v]) {
                if (u == parent[v]) continue;

                long long without_u = sumPos[v];
                if (dp1[u] > 0) without_u -= dp1[u];

                up[u] = val[v] + without_u + max(0LL, up[v]);
                st.push_back(u);
            }
        }
    }
    vector<int> res(n);
    for (int i = 1; i <= n; ++i) {
        long long ans = dp1[i] + max(0LL, up[i]);
        res[i - 1] = (int)ans;
    }
    return res;
}

// /* If needed for local testing:

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> from(n - 1), to(n - 1), strong(n);
    for (int i = 0; i < n - 1; ++i) cin >> from[i];
    for (int i = 0; i < n - 1; ++i) cin >> to[i];
    for (int i = 0; i < n; ++i) cin >> strong[i];

    auto ans = getNeuronStrengths(n, from, to, strong);
    for (int x : ans) cout << x << ' ';
    cout << "\n";
}


