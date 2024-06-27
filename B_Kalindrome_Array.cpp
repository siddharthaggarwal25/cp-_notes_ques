#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        set<int> ans;
        int i = 0;
        int j = n - 1;
        while (i < j)
        {
            if (arr[i] != arr[j])
            {
                int count = ans.count(arr[i]);
                int count2 = ans.count(arr[j]);
                if (count == 1)
                {
                    i++;
                }
                else if (count2 == 1)
                {
                    j--;
                }
                else
                {
                    ans.insert(arr[i]);
                    i++;
                }
            }
            else
            {
                i++;
                j--;
            }
        }
        if (ans.size() < 2)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}