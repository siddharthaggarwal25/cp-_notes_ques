#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, k;
        cin >> x >> y >> k;

        int g = __gcd( x, y );

        if( x/g <= k && y/g <= k )cout<<1<<endl;
        else cout<<2<<endl;

    }
    return 0;
}