#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll k;
    if (!(cin >> n >> k)) return 0;

    if (k == 1) { // trivial: nothing to extract meaningfully
        cout << 0 << '\n';
        return 0;
    }

    // Factorize k into (prime, exponent)
    vector<pair<ll,int>> factors;
    ll tmp = k;
    for (ll p = 2; p * p <= tmp; ++p){
        if (tmp % p == 0){
            int e = 0;
            while (tmp % p == 0){
                tmp /= p;
                ++e;
            }
            factors.emplace_back(p, e);
        }
    }
    if (tmp > 1) factors.emplace_back(tmp, 1);

    // total exponents collected for each prime factor of k
    vector<ll> total(factors.size(), 0);

    for (int i = 0; i < n; ++i){
        ll a; cin >> a;
        for (size_t j = 0; j < factors.size(); ++j){
            ll p = factors[j].first;
            while (a % p == 0){
                a /= p;
                ++total[j];
            }
        }
    }

    // answer is min over primes of floor(total_exponent / required_exponent)
    ll ans = LLONG_MAX;
    for (size_t j = 0; j < factors.size(); ++j){
        ans = min(ans, total[j] / factors[j].second);
    }
    if (ans == LLONG_MAX) ans = 0; // defensive (shouldn't happen because k>1)

    cout << ans << '\n';
    return 0;
}