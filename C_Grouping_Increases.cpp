// ai is less than  n , impk point int t;com
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        int a = INT_MAX;
        int b = INT_MAX;
        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            int value = arr[i];
            if (a < value &&  value<= b)
            {
                b = value;
            }
            else if (value <= a)
            {
                a = value;
            }
            else
            {
                ans++;
                a = value;
            }
            int c = max(a, b);
            int d = min(a, b);
            a = d;
            b = c;
        }

        cout << ans << endl;
        return 0;
    }
}