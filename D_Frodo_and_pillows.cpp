#include <bits/stdc++.h>
using namespace std;
#define int long long


int sideSum(int len, int peak) {
    peak --;
    if (len < peak) {
        int lowest = peak - len +1;
        return (peak  + lowest) * len / 2;
    } else {
        int full = (peak+1 ) * peak / 2;
        return full + (len - peak );
    }
}

bool check(int peak, int n, int m, int k) {
    int left = k - 1;
    int right = n - k;

    int total = peak + sideSum(left, peak) + sideSum(right, peak);
    return total <= m;
}

int32_t main() {
    int n, m, k;
    cin >> n >> m >> k;

    int low = 1, high = m, ans = 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(mid, n, m, k)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}
