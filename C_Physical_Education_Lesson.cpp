#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int count = 0;
        for (int i = 2; i <= n; i++)
        {
            int value = 2 * i - 2;
            if (n % value == x || n % value == 0)
            {
                cout << i << " ";
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}

