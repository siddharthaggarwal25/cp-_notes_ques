#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n >> k >> x;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + n);
        int value = 0;
        int j = n - x;

        for (int i = 0; i < j; i++)
        {

            value += arr[i];
        }

        for (int i = j; i < n; i++)
        {
            value -= arr[i];
        }

        int total = value;
        for (int i = n - 1; i >= n - k; i--)
        {
            if (i >= j)
            {
                value = value + arr[i];
                if (j - 1 >= 0)
                {
                    value = value - 2 * arr[j - 1];
                }
                total = max(total, value);
                j--;
            }
        }

        cout << total << endl;
    }
    return 0;
}