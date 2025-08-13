#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r, b;
        cin >> n >> r >> b;

        int dis = r / (b + 1);
        int mod = r % (b + 1);

        string R(dis, 'R');
        string ans = "";

        while (ans.size() < n) {
            ans += R;
            if (mod > 0) {
                ans += 'R';
                mod--;
            }
            if (ans.size() < n) ans += 'B';
        }

        cout << ans << "\n";
    }
    return 0;
}
