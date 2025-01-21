#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Function to calculate the maximum bonding value
ll max_bond(vector<ll>& p, vector<ll>& r) {
    int n = p.size();
    ll mwr = p[0];  // max without replacement
    ll mwrp = r[0]; // max with replacement
    ll mafr = LLONG_MIN; // max after replacement

    ll res = max(mwr, mwrp);

    for (int i = 1; i < n; ++i) {
        ll pmwr = mwr;
        ll pmwrp = mwrp;
        ll pmafr = mafr;

        // Update mwr
        mwr = max(p[i], pmwr + p[i]);

        // Update mwrp
        mwrp = max({pmwrp + r[i], pmwr + r[i], r[i]});

        // Update mafr
        mafr = max({pmwrp + p[i], pmafr + p[i], p[i]});

        // Update result
        res = max({res, mwr, mwrp, mafr});
    }

    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> p(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    cout << max_bond(p, r) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; 
    // Uncomment the next line if multiple test cases are required
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
