#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    vector<pair<int, int>> tv(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tv[i].first >> tv[i].second;
    }
    sort(tv.begin(), tv.end());

    int tv1 = -1, tv2 = -1;
    bool ans = true;

    for (int i = 0; i < n; i++)
    {

        if (tv1 == -1)
        {
            tv1 = tv[i].second;
        }
        else if (tv1 < tv[i].first)
        {
            tv1 = tv[i].second;
        }
        else if (tv2 == -1)
        {
            tv2 = tv[i].second;
        }
        else if (tv2 < tv[i].first)
        {
            tv2 = tv[i].second;
        }
        else
        {
            ans = false;
            break;
        }
    }

    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}