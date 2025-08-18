#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> place(m);
        for (int i = 0; i < m; i++)
            cin >> place[i];
        sort(place.begin(), place.end());

        vector<int> gaps;
        for (int i = 0; i < m - 1; i++)
        {
            gaps.push_back(place[i + 1] - place[i] - 1);
        }
        gaps.push_back(n - place[m - 1] + place[0] - 1);

        sort(gaps.begin(), gaps.end(), greater<>());

        int infected = 0;
        int days = 0;

        for (int gap : gaps)
        {
            int effective = gap - 2 * days;
            if (effective <= 0)
                break;
            if (effective == 1)
                infected += 1;
            else
                infected += (effective - 1);
            days += 2;
        }

        cout << n - infected << "\n";
    }
    return 0;
}
