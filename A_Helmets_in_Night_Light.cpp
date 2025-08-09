#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i].second;
        for (int i = 0; i < n; i++)
            cin >> v[i].first;
        sort(v.begin(), v.end());

        int ans = k;
        int left = n-1;
        int ind = 0;
        while (left && v[ind].first <= k)
        {
            if (left >= v[ind].second)
            {
                ans  += v[ind].second*v[ind].first;
                left -= v[ind].second;
            }
            else
            {
                ans  += left*v[ind].first;
                left =0 ;
            }
            ind++;
        }
        ans += (left*k);
        cout<<ans<<endl;
    }
    return 0;
}