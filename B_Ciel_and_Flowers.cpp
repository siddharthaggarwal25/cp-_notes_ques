#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, g, b;
    cin >> r >> g >> b;

    int ans = 0;
    for (int take = 0; take <= 2; ++take) {
        if (r >= take && g >= take && b >= take) {
            int rr = r - take;
            int gg = g - take;
            int bb = b - take;
            int bouquets = take + (rr / 3) + (gg / 3) + (bb / 3);
            ans = max(ans, bouquets);
        }
    }
    cout << ans << endl;
    return 0;
}