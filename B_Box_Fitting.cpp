#include <bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, w;
        cin >> n >> w;
        map<int,int,greater<>> mp;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            mp[x]++;
        }

        int height = 0;
        int remaining = n; // total items left

        while (remaining > 0) {
            int temp = w;
            height++;
            for (auto &it : mp) {
                int take = min(it.second, temp / it.first);
                temp -= take * it.first;
                it.second -= take;
                remaining -= take;
            }
        }
        cout << height << "\n";
    }
    return 0;
}
