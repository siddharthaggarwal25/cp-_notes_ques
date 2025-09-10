#include <bits/stdc++.h>
using namespace std;
#define int long long

int check( int n , int mid ){
     int val =  n*( pow( 10 ,mid.size() ) - )
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int low = 1;
        int high = 1e9;
        int ans;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            int temp = check(n, mid);
            if (temp)
            {
                ans = mid;
                break;
            }
            else if (temp > 0)
            {
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