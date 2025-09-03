#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main() {
  

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int > xs(n), ys(n);
        for (int i = 0; i < n; i++) cin >> xs[i] >> ys[i];

        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());

        int  countX, countY;

        if (n % 2 == 1) {
            countX = 1;
            countY = 1;
        } else {
            int mid = n / 2;
            countX = xs[mid] - xs[mid - 1] + 1;
            countY = ys[mid] - ys[mid - 1] + 1;
        }

        cout << countX * countY << "\n";
    }
}
