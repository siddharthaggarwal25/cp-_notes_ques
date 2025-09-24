#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        map<int, int> mp;
        vector<int> ones;
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
                ones.push_back(i);
            mp[a[i]]++;
        }

        bool isDup = false;
        for (auto it : mp)
        {
            if (it.second >= 2)
                isDup = true;
        }

        if (isDup || (ones.size() > 0 && ones[0] > 0))
        {
            cout << 1 << endl;
        }
        else
        {
            int maxi = *max_element(a.begin(), a.end());
            cout << n - maxi + 1 << endl;
        }
    }
    return 0;
}