#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        if (m < n || m > (n * (n + 1)) / 2) {
            cout << -1 << endl;
            continue;
        }

        vector<int> used(n + 1, 0); 
        vector<int> ans;
        int remaining = n;

        for (int i = n; i >= 1; i--) {
            if (m - i > remaining - 1) {
                used[i] = 1;
                ans.push_back(i);
                m -= i;
                remaining--;
            } else if (m - i == remaining - 1) {
                used[i] = 1;
                ans.push_back(i);
                m -= i;
                remaining--;
                break;
            }
        }


        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                ans.push_back(i);
            }
        }

        cout<<ans[0]<<endl;
        for (int i = 0; i < ans.size() - 1; i++) {
            cout << ans[i] << " " << ans[i + 1] << endl;
        }
    }

    return 0;
}
