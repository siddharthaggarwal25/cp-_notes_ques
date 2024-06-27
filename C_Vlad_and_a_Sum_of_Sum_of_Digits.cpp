#include <bits/stdc++.h>
using namespace std;
#define int long long 
int ans[1000000];

int32_t main()
{

    for (int i = 1; i < 1000000; i++)
    {
        int val = 0;
        int num = i;
        while (num > 0)
        {
            val = val + (num % 10);
            num = num / 10;
        }
        ans[i] = ans[i - 1] + val;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}