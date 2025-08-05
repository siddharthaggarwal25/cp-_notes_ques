#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> p(n + 1), s(n + 1);
        for (int i = 1; i <= n; i++) cin >> p[i];
        for (int i = 1; i <= n; i++) cin >> s[i];

        bool ok = true;

        for (int i = 2; i <= n; i++) {
            if (p[i - 1] % p[i] != 0) ok = false;
        }
        for (int i = 1; i < n; i++) {
            if (s[i + 1] % s[i] != 0) ok = false;
        }

        if (p[n] != s[1]) ok = false;

        long long g = p[n];
        vector<long long> P(n + 1), S(n + 1);
        for (int i = 1; i <= n; i++) {
            P[i] = p[i] / g;
            S[i] = s[i] / g;
        }

        for (int i = 2; i <= n; i++) {
            long long x = p[i - 1] / p[i];
            if (__gcd(x, S[i]) != 1) ok = false;
        }

        for (int i = n - 1; i >= 1; i--) {
            long long y = s[i + 1] / s[i];  
            if (__gcd(y, P[i]) != 1) ok = false;
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
}
