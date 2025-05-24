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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        set<int> st;
        for (int i = 0; i < n; i++)
        {
            if (b[i] != -1)
                st.insert(a[i] + b[i]);
        }

        if (st.size() == 0)
        {
            int mini = *min_element(a.begin(), a.end());
            int maxi = *max_element(a.begin(), a.end());
            int maxpossible = mini + k;
            int ans = maxpossible - maxi + 1;
            cout << ans << endl;
        }
        else if (st.size() == 1)
        {
            bool check = true;
            for (int i = 0; i < n; i++)
            {
                if (b[i] == -1)
                {
                    int cur = *st.begin() - a[i];
                    if (cur > k || cur<0 )
                        check = false;
                    else
                        b[i] = cur;
                }
            }

            if (check)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}