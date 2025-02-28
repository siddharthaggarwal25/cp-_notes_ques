#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 1;
        ans += (n / 15) * 3;
        n = n % 15;
        if (n == 0)  ans = ans ;
        else if( n==1) ans++;   
        else ans += 2;
        cout << ans << endl;
    }
    return 0;
}