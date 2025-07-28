#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, ans = -1;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        // Check for adjacent elements with difference <= 1
        for (int i = 1; i < n; ++i) {
            if (abs(a[i] - a[i - 1]) <= 1) {
                ans = 0;
                break;
            }
        }

        // If not found, check for local extrema
        if (ans == -1) {
            for (int i = 1; i < n - 1; ++i) {
                if ((a[i - 1] < a[i] && a[i] > a[i + 1]) ||
                    (a[i - 1] > a[i] && a[i] < a[i + 1])) {
                    ans = 1;
                    break;
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}