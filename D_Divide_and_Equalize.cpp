#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1000000; // 1e6
int spf[MAXN + 1];         // smallest prime factor for every number

// Precompute SPF using sieve
void sieve()
{
    for (int i = 2; i <= MAXN; i++)
        spf[i] = i;
    for (int i = 2; i * i <= MAXN; i++)
    {
        if (spf[i] == i)
        { // i is prime
            for (int j = i * i; j <= MAXN; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

int32_t main()
{
    int t;
    cin >> t;
    sieve();
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
            cin >> v[i];

        for (int i = 0; i < n; i++)
        {
            int num = v[i];
            while (num > 1)
            {
                int p = spf[num];
                num /= p;
                mp[p]++;
            }
        }

        bool ans = true;
        for (auto it : mp)
        {
            if (it.second % n != 0)
                ans = false;
        }

        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}
