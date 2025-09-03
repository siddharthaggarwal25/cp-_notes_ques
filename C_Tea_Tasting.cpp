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
        vector<int> chai(n + 1), capacity(n + 1), prefix(n + 1), ans(n + 2);
        map<int, int> mp;

        for (int i = 1; i <= n; i++) cin >> chai[i];
        for (int i = 1; i <= n; i++) cin >> capacity[i];
        for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + capacity[i];

        for (int i = 1; i <= n; i++) {
            int val = chai[i] + prefix[i - 1];
            int ind = lower_bound(prefix.begin(), prefix.end(), val) - prefix.begin();

            ans[i] += 1;
            if (ind <= n) ans[ind] -= 1;

            if (ind <= n && val > prefix[ind - 1]) {
                mp[ind] += val - prefix[ind - 1];
            }
        }

        for (int i = 1; i <= n; i++) ans[i] += ans[i - 1];

        for (int i = 1; i <= n; i++) {
            cout << capacity[i] * ans[i] + mp[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
