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
        vector<int> febo(14);
        febo[0] = 1;
        febo[1] = 1;
        for (int i = 2; i < 12; i++)
        {
            febo[i] = febo[i - 1] + febo[i - 2];
        }
        int dim1 = febo[n];
        int dim2 = febo[n] + febo[n - 1];
        string ans = "";
        while (m--)
        {
            int w, l, h;
            cin >> w >> l >> h;

            if (dim1 <= w && dim1 <= l && dim2 <= h)
                ans += "1";
            else if (dim2 <= w && dim1 <= l && dim1 <= h)
                ans += "1";
            else if (dim2 <= l && dim1 <= w && dim1 <= h)
                ans += "1";
            else
                ans += "0";
        }
        cout << ans << endl;
    }
    return 0;
}