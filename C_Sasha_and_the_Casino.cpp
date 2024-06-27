#include <bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
  {
        int k, x, n;
        cin >> k >> x >> n;
        int loss = 1;
        bool check = true;
        for (int i = 2; i <= x ; i++)
        {
            int z = loss/(k-1);
            while ((z * (k - 1)) <=loss)
            {
                z++;
            }
            loss += z;
            if (loss >= n)
            {
                check = false;
                break;
            }
        }

    
        int after = k * (n - loss);
        if (after > n && check)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
