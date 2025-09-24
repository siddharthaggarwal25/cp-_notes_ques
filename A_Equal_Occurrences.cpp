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
        vector<int> temp(n);
        int ele = -1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (ele != x)
            {
                temp.push_back(cnt);
                ele = x;
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
        temp.push_back(cnt);
        sort(temp.begin(), temp.end(), greater<int>());

        int ans = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            ans = max(ans, temp[i] * (i + 1));
        }
        cout << ans << endl;
    }
    return 0;
}