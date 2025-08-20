#include <bits/stdc++.h>
using namespace std;
#define int long long 
bool check(int num, int n, int k)
{

    int cur = 0;
    if (num <= n)
    {
        int temp = (num * (num + 1) / 2) - num;
        if ( temp < k)
            return true;
        else
            return false;
    }

    k = k - (n * (n + 1) / 2);
    num = num - n;
    n--;
    int  temp = num*( 2*n  + 1 - num)/2 - ( n- num + 1);

    if(temp <k )return true ;
    return false;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int low = 1;
        int high = 2 * n - 1;
        int ans = 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(mid, n, k))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}