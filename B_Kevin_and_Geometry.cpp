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
        vector<int> v(n), v2;
        for (int i = 0; i < n; i++)cin >> v[i];
        sort(v.begin(), v.end());
        int ind = -1;
        for (int i = n - 1; i >= 1; i--)
        {
            if (v[i] == v[i - 1])
            {
                ind = i;
                break;
            }
        }

        if (ind == -1)
        {
            cout << -1 << endl;
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            if (i == ind || i == (ind - 1))continue;
            v2.push_back(v[i]);
        }

        int diff = 1e16;
        int b, c;
        for (int i = 0; i < v2.size() - 1; i++)
        {
            if (v2[i + 1] - v2[i] < diff)
            {
                b = v2[i];
                c = v2[i + 1];
                diff = c- b ;
            }
        }

        if (diff == 1e9)
        {
            cout << -1 << endl;
        }
        else if ((2 * v[ind]) >  diff)
        {
            cout << v[ind] << " " << v[ind] << " " << b << " " << c << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}