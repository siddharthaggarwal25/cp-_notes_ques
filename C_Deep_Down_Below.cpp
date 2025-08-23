#include <bits/stdc++.h>
using namespace std;
#define int long long

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> maxi(n);

        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            maxi[i].second = k;
            maxi[i].first = 0;
            for (int j = 0; j < k; j++) {
                int x;
                cin >> x;
                x -= j;  // shift because of index
                maxi[i].first = max(maxi[i].first, x);
            }
        }

        sort(maxi.begin(), maxi.end(), comp);

        int ans = maxi[0].first + 1;
        int cur = maxi[0].first + maxi[0].second + 1;

        for (int i = 1; i < n; i++) {
            if (cur > maxi[i].first) {
                cur += maxi[i].second;
            } else {
                ans += (maxi[i].first - cur + 1);
                cur = m
