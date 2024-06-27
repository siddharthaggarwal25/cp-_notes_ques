#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int n, h;
    cin >> n >> h;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int ans = 1;
    for (int i = 1; i <= n; i++)
    {

        sort(arr + 1, arr + i + 1);
        reverse(arr + 1, arr + i + 1);
        int count = 0;
        int val = 0;

        for (int j = 1; j <= i; j++)
        {

            if (i % 2 == 0)
            {
                int curr = arr[j];
                if (val + curr <= h)
                {
                    count += 2;
                    val += curr;
                }
                j++;
            }
            else
            {

                if (j - i == 0)
                {
                    int curr = arr[j];
                    if (val + curr <= h)
                    {
                        count++;
                        val += curr;
                    }
                }
                else
                {
                    int curr = arr[j];
                    if (val + curr <= h)
                    {
                        count += 2;
                        val += curr;
                    }
                    j++;
                }
            }

            ans = max(ans, count);
        }
    }
    cout << ans << endl;
    // cout<<endl;

    return 0;
}