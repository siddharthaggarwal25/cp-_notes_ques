#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int n;
    cin >> n;

    int ans = 0;
    int temp = 0;
    while (n > 0)
    {
        int last_digit = n % 10;
        if (n == 9)
        {
            ans += (pow( 10 , temp )) * 9;
            break;
        }
        ans += (pow( 10 , temp )) * (min(last_digit, 9 - last_digit));

        temp++;
        n = n / 10;
    }
    cout << ans << endl;
    return 0;
}