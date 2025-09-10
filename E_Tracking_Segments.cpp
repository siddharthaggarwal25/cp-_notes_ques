#include <bits/stdc++.h>
using namespace std;
bool check(vector<pair<int, int>> &v, vector<int> &x, int mid, int n)
{

    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= mid; i++)
        arr[x[i]] = 1;
    for (int i = 1; i <= n; i++)
        arr[i] += arr[i - 1];

    for (int i = 0; i < v.size(); i++)
    {
        
        int l = v[i].first;
        int r = v[i].second;

        if (2 * (arr[r] - arr[l - 1]) > (r - l + 1))
            return true;
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> v(m);
        for (int i = 0; i < m; i++)
        {
            cin >> v[i].first >> v[i].second;
        }
        int q;
        cin >> q;
        vector<int> x(q+1);
        for (int i = 1; i <=  q; i++)
            cin >> x[i];

        int low = 1;
        int high = q ;
        int ans = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (check(v, x, mid, n))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        cout << ans  << endl;
    }
    return 0;
}