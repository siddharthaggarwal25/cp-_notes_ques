#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> h(n);

        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }

        int diff = h[k - 1];
        int curr = h[k - 1];
        bool ans = true;
        sort(h.begin(), h.end());

        for (int i = 0; i < n; i++)
        {
            if (h[i] < curr)
                continue;

            if (h[i] - curr > diff)
            {
                ans = false;
                break;
            }
            curr = h[i];
        }

        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}