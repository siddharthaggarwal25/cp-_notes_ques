#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        if (n == 1) {
            cout << 0 << "\n";
            continue;
        }

        int ans = 0;
        for (int i = 0; i < n /2; i++) {
            int diff = abs(v[i] - v[n - i - 1]);
            ans = __gcd(ans, diff);
        }

        cout << ans << "\n";
    }
    return 0;
}
