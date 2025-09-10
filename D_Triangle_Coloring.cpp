#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;

const int MAXN = 200005; 
int fact[MAXN], invfact[MAXN];

int modpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void precompute()
{
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = fact[i - 1] * i % mod;
    invfact[MAXN - 1] = modpow(fact[MAXN - 1], mod - 2);
    for (int i = MAXN - 2; i >= 0; i--)
        invfact[i] = invfact[i + 1] * (i + 1) % mod;
}

int ncr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    int ans = 1;
    for (int i = 1; i <= n; i += 3)
    {
        int a = min({v[i], v[i + 1], v[i + 2]});
        int c = max({v[i], v[i + 1], v[i + 2]});
        int b = v[i] + v[i + 1] + v[i + 2] - a - c;

        if (a == b && b == c)
            ans = ans * 3 % mod;
        else if (a == b && a < c)
            ans = ans * 2 % mod;
        else
            ans = ans * 1 % mod;
    }

    int temp = ncr(n / 3, n / 6) % mod;
    ans = ans * temp % mod;
    cout << ans << "\n";
    return 0;
}
