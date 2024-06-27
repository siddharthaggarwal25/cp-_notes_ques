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
        vector<int> v1;
        vector<int> v2;
        vector<int> v3;

        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            if (x == 1)
            {
                v1.push_back(y);
            }
            else if (x == 2)
            {
                v2.push_back(y);
            }
            else
            {
                v3.push_back(y);
            }
        }

        int minValue = *max_element(v1.begin(), v1.end());
        int maxValue = *min_element(v2.begin(), v2.end());

        int ans = maxValue - minValue + 1;

        for (int i = 0; i < v3.size(); i++)
        {

            if (v3[i] >= minValue && v3[i] <= maxValue)
            {
                ans--;
            }
        }

        if (ans < 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}