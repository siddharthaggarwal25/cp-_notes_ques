#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int sum = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        sort( a.begin() , a.end());
        a[n-1]--;
        sort( a.begin() , a.end());
        int diff = a[n-1] - a[0];

        if (diff > k)
        {
            cout << "Jerry" << endl;
        }
        else
        {
            if (sum % 2 == 0)
                cout << "Jerry" << endl;
            else
                cout << "Tom" << endl;
        }
    }

    return 0;
}