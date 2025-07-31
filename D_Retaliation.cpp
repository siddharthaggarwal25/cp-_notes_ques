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
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> v[i];

        int num = 2 * v[1] - v[2];
        int den = n + 1;
        int y = num / den;
        int x = v[1] - n * y;

        bool ans = true;

        for (int i = 1; i <= n; i++)
        {
            if (i * x + (n - i + 1) * y != v[i])
                ans = false;
        }

        if (!ans || y< 0 || x < 0 )
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}