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
        vector<int> v(n), prefix(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            prefix[i] = v[i];
        }
        sort(prefix.begin(), prefix.end());
        for (int i = 1; i < n; i++)
        {
            prefix[i] += prefix[i - 1];
        }
        prefix.push_back( 1e18);

        for (int i = 0; i < n; i++)
        {
            int val = v[i];
            int cnt = (upper_bound(prefix.begin(), prefix.end(), val) - prefix.begin()) ;
            cout << cnt << " ";
        }
        cout << endl;
    }
    return 0;
}