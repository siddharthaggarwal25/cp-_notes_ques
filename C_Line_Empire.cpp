#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18 + 8;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        int n;
        ll a, b;
        cin >> n >> a >> b;

        vector<ll> x(n + 1), pre(n + 1);
        for (int i = 1; i <= n; i++) cin >> x[i];
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + x[i];

        ll ans = INF;
        for (int i = 0; i <= n; i++) {
            ll cost = (a + b) * x[i] + b * (pre[n] - pre[i] - 1LL * (n - i) * x[i]);
            ans = min(ans, cost);   
        }
        cout << ans << "\n";
    }
}
