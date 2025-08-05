#include <bits/stdc++.h>
using namespace std;
#define int long long

int getIdx(int n, int x, int y) {
    int res = 1, sz = 1 << n;
    while (sz > 1) {
        int h = sz / 2, blk = h * h;
        if (x <= h && y <= h) {}
        else if (x <= h && y > h) { res += 3 * blk; y -= h; }
        else if (x > h && y <= h) { res += 2 * blk; x -= h; }
        else { res += blk; x -= h; y -= h; }
        sz = h;
    }
    return res;
}

pair<int, int> getCoord(int n, int d) {
    int x = 1, y = 1, sz = 1 << n;
    while (sz > 1) {
        int blk = (sz * sz) / 4;
        int r = (d - 1) / blk + 1;
        d = (d - 1) % blk + 1;
        if (r == 2) { x += sz / 2; y += sz / 2; }
        else if (r == 3) x += sz / 2;
        else if (r == 4) y += sz / 2;
        sz /= 2;
    }
    return {x, y};
}

int32_t main() {
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        while (q--) {
            string s; cin >> s;
            if (s == "->") {
                int x, y; cin >> x >> y;
                cout << getIdx(n, x, y) << '\n';
            } else {
                int d; cin >> d;
                auto [x, y] = getCoord(n, d);
                cout << x << " " << y << '\n';
            }
        }
    }
    return 0;
}
