#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int odd_even, bool is_once, vector<int> &v) {
    if (ind >= v.size()) return 0;

    int ans = 0;
    if (is_once) {
        if (odd_even == 1) {
            if (ind % 2 == 1) {
                ans = v[ind];
            }
            ans += max(solve(ind + 1, 1, 1, v), solve(ind + 1, 0, 1, v));
        } else { // odd_even == 0
            if (ind % 2 == 0) {
                ans = v[ind];
            }
            ans += solve(ind + 1, 0, 1, v);
        }
    } else {
        if (ind % 2 == 0) {
            ans = v[ind];
        }
        ans += max(solve(ind + 1, 0, 0, v), solve(ind + 1, 1, 1, v));
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int val1 = solve(0, 0, false, v);
        int val2 = solve(0, 1, true, v);
        cout << max(val1, val2) << endl;
    }
    return 0;
}
