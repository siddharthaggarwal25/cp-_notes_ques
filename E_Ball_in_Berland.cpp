#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, k;
        cin >> a >> b >> k;
        vector<pair<int, int>> v(k);
        for (int i = 0; i < k; i++)
            cin >> v[i].first;
        for (int i = 0; i < k; i++)
            cin >> v[i].second;
        int ans = 0;
        map<int, int> freq_a, freq_b;
        for (int i = 0; i < k; i++)
        {
            freq_a[v[i].first]++;
            freq_b[v[i].second]++;
        }
        int totalPairs = 1LL * k * (k - 1) / 2;
        int badPairs = 0;

        for (int i = 0; i < k; i++)
        {
            badPairs += (freq_a[v[i].first] - 1);
            badPairs += (freq_b[v[i].second] - 1);
        }
        int goodPairs = totalPairs - badPairs / 2;

        cout << goodPairs << '\n';
    }
    return 0;
}