#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int y, k, n;
    cin >> y >> k >> n;

    int first_x = k - y % k;
    if (y + first_x > n) {
        cout << -1 << endl;
    } else {
        for (int x = first_x; y + x <= n; x += k) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
