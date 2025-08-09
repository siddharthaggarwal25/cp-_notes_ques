#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        // Append a unique sentinel to flush the last run
        const int SENTINEL = INT_MIN;
        a.push_back(SENTINEL);
        b.push_back(SENTINEL);

        unordered_map<int, int> m1, m2;
        int ans = 1;

        // Process array a
        int cur = a[0], len = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == cur) {
                len++;
            } else {
                m1[cur] = max(m1[cur], len);
                ans = max(ans, len);
                cur = a[i];
                len = 1;
            }
        }

        // Process array b
        cur = b[0], len = 1;
        for (int i = 1; i <= n; i++) {
            if (b[i] == cur) {
                len++;
            } else {
                m2[cur] = max(m2[cur], len);
                ans = max(ans, len);
                cur = b[i];
                len = 1;
            }
        }

        // Check common elements
        for (auto &it : m1) {
            if (m2.count(it.first)) {
                ans = max(ans, it.second + m2[it.first]);
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
