#include <bits/stdc++.h>
using namespace std;

#define int long long 

int32_t main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k, b, s;
        cin >> n >> k >> b >> s;

        int min_sum = b * k;
        int max_sum = b * k + n * (k - 1);

        if (s < min_sum || s > max_sum) {
            cout << -1 << "\n";
            continue;
        }

        vector<int> a(n, 0);
        a[0] = b * k;
        s -= a[0];

        for (int i = 0; i < n && s >= 0; i++) {
            int add_val = min(s, k - 1);
            a[i] += add_val;
            s -= add_val;
        }

        for (auto x : a) cout << x << " ";
        cout << "\n";
    }
}
