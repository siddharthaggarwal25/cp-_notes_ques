#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<int>());

    int ans = 0;
    int ind = 0;

    while (ind < n && k > 0)
    {
        int x = v[ind];
        int y = 0 ;
        if( ind +1 <n ){
            y = v[ind+1];
        }

        int count = ind + 1;

        if ((x - y) * count <= k)
        {
            ans +=  count *(  ( x*( x+1)/2) - ( y*(y+1)/2)) ;
            k -= (x - y) * count;
            ind++;
        }
        else
        {
            int c = k / count;
            int r = k % count;

            ans += count * ( ( x*(x+1)/2 ) -  ((x-c)*( x-c+1)/2));
            ans += r * (x - c);
            k = 0;
        }
    }

    cout << ans << endl;

    return 0;
}