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
        int arr[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        int val = arr[1];
        int val2 = arr[n];

        int count = 0;
        int count2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] == val)
            {
                count++;
            }
            else
            {
                break;
            }
        }
        for (int j = n; j >= 1; j--)
        {
            if (arr[j] == val2)
            {
                count2++;
            }
            else
            {
                break;
            }
        }

        int z, ans;
        if (val != val2)
        {
            z = max(count, count2);
        }
        else
        {
            z = count + count2;
        }

        if (count  == n && count2 == n)
        {
            ans = 0;
        }
        else
        {
            ans = n - z;
        }
        cout << ans << endl;
    }
    return 0;
}