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
        int ans = 0;
        for (int i = 0; i <= 60; i++)
        {
           if( n& ( 1LL<<i)){
                 ans += ( ( 1LL<< ( i+1)) -1 );
           }
            
        }
        cout << ans << endl;
    }
    return 0;
}