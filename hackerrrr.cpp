#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fr(k, n, i) for (int i = k; i < n; i++)
#define yay cout << "YES" << '\n'
#define na cout << "NO" << '\n'
#define m 1000000007
#define o(x) (x).order_of_key
#define v vector<ll>
#define pi pair<ll, ll>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define co(w) w ? cout << "YES" << '\n' : cout << "NO" << '\n'
#define ou(x) cout << x << '\n'
#define dbg(x) cout << x << " ";
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

ll inf = 1e18;

const ll lim = 1e7 + 5;
ll dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
ll dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

// vector<ll> pri(lim+1,0);
// vector<ll> spf(lim+1);

// void seive(ll lim) {
//     ll tem=1;
//     pri[1]=1;
//     for(ll i=2;i<=lim;i++) spf[i]=i;
//     for (ll i = 2; i<= lim; i++) {
//         if (spf[i]==i) {
//             pri[i]=(i&1)?++tem:0;
//             for (ll j = i * i; j <= lim; j += i) {
//                 if(spf[j]==j)spf[j]=i;
//                 pri[j]=pri[spf[j]];
//             }
//         }

//     }

// }

ll gcd(ll a, ll b)
{
    return (b == 0) ? (a) : (gcd(b, a % b));
}

ll power(ll a, ll b)
{
    if (b == 0)
        return 1 % m;
    ll res = 1;
    ll cur = a % m;
    while (b > 0)
    {
        if (b & 1)
            res = (res * cur) % m;
        cur = (cur * cur) % m;
        b >>= 1;
    }
    return (res);
}

ll bitco(ll x)
{
    if (x == 1)
        return 0;
    ll te = 0;
    while (x)
    {
        te++;
        x /= 2;
    }
    return te;
}

const ll N = 2e5 + 3;

void solve()
{
    ll n, k;
    cin >> n >> k;
    long double rem = double(n - 1) / n;
    long double pro = double(k) / 100;
    long double ans = pow(pro, rem);
    ans = (ans - pro) * 100;
    ou(ans);
}

int main()
{
    fastIO;
    ll t = 1;
    cin >> t;
    cout << fixed << setprecision(15);
    fr(0, t, i)
    {
        clock_t start_time = clock();
        cout << "Case #" << i + 1 << ": ";
        solve();
        double elapsed_time = double(clock() - start_time) / CLOCKS_PER_SEC;
        // cout << "Time (seconds): " << elapsed_time <<'\n';
    }
    return 0;
}