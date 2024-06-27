#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c, d;
        cin >> n >> c >> d;
        int arr[n * n];
        for (int i = 0; i < n * n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n * n);
        int minm = arr[0];

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int cur = minm + c * i;
            for (int j = 0; j < n; j++)
            {
                ans.push_back(cur + j * d);
            }
        }
        sort(ans.begin(), ans.end());

        bool flag = true;
        for (int i = 0; i < n * n; i++)
        {
            if (arr[i] != ans[i])
            {
                flag = false;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}