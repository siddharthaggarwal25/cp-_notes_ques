#include <bits/stdc++.h>
using namespace std;
#define int long long int 
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, r;
        cin >> a >> b >> r;

        if (b > a)
            swap(a, b);
        int flag = 0;
        int x = 0;

        for (int i = 63; i >= 0; i--)
        {

            if ((a & (1ll << i)) && !(b & (1ll << i)) && flag == 0)
            {
                flag = 1;
                continue;
            }
            if ((a & (1ll << i)) && !(b & (1ll << i)))
            {
                if ((x + (1ll << i)) <= r)
                {
                    x = x +( 1ll << i);
                    // a ^= 1ll<<i;
                    // b ^= 1ll<<i;
                }
            }
        }
        cout << abs((a ^ x) - (b ^ x)) << endl;
    }
    return 0;
}