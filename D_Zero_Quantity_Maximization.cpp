#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
    int t;
    t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        map<pair<int, int>, int> mp;
        int ans = 0;
        
        for (int i = 0; i < n; i++)
        {

            if (a[i] == 0 && b[i] == 0) ans++;
            else if (a[i] == 0 && b[i] != 0) continue;
            else
            {
                int temp = __gcd(b[i], a[i]);
                if( b[i] ==0 ) mp[ { 0 ,0  }]++;
                else mp[{b[i] / temp, a[i] / temp}]++;
            }
        }
        int temp =0 ;
        for (auto it : mp)
        {
            temp = max(temp , it.second);
        }
        ans += temp;
        cout << ans << endl;
    }
    return 0;
}
