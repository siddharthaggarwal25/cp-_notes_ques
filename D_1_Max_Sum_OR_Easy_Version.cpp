#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int n = r - l + 1;

        vector<int> v(n);
        vector<bool> temp(n, false);
        for (int i = 0; i < n; i++)
            v[i] = i;
        int limit = 0;
        if( n%2 ==1)limit++;    
        for (int i = n - 1; i >=limit ; i--)
        {
            if (!temp[i])
            {

                int ind = 0;
                for (int k = 0; k <= 31; k++)
                {
                    if ((1 << k) & i)
                        ind = k;
                }
                ind++;

                int a = (1 << ind) - i - 1;
                v[i] = a;
                v[a] = i;

                temp[i] = true;
                temp[a] = true;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += (i | v[i]);
        }
        cout << ans << endl;
        // int i = 0;
        for (auto it : v)
        {
        cout   <<it << " ";
            // i++;
        }
        cout << endl;
    }
    return 0;
}