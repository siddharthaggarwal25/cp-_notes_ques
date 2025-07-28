#include <bits/stdc++.h>
using namespace std;

int main() {
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> v[i];

        vector<int> prefix(n + 1), suffix(n + 2);

        int mini = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            mini = min(mini, v[i]);
            prefix[i] = mini;
        }

        int maxi = INT_MIN;
        for (int i = n; i >= 1; --i) {
            maxi = max(maxi, v[i]);
            suffix[i] = maxi;
        }

        string ans(n, '1');
        for (int i = 2; i <= n - 1; ++i) {
    
            if (!(prefix[i] == v[i] || suffix[i] == v[i]))
                ans[i - 1] = '0';
        }
        cout << ans << '\n';
    }
    return 0;
}
