#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin >> n;
    int value = (n * (n + 1)) / 2;

    if (value % 2 == 0)
    {
        cout << "YES" << endl;
        int n2 = n;
        int ans = 0;
        vector<int> v;
        int miss = 0;
        while (ans != (value / 2))
        {
            if (ans + n <= (value / 2))
            {
                ans += n;
                v.push_back(n);
                n--;
            }
            else
            {
                v.push_back(value / 2 - ans);
                miss = (value / 2 - ans);
                ans = value / 2;
            }
        }

        cout << v.size() << endl;
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
        cout << n2 - v.size() << endl;
        for (int i = 1; i <= (n2 - v.size() + 1); i++)
        {
            if (i != miss)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
