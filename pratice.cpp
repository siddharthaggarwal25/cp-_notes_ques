#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int maxm = -1e9;
        int minm = 1e9;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= l && arr[i] <= r)
                count++;
            else
                count--;
            minm = min(count, minm);
            maxm = max(maxm, count);
        }
        cout << maxm << minm << endl;
    }
}
