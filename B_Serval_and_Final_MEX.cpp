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
        stack<int> s;
        vector<int> v(n);
        vector<pair<int, int>> ans;

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] != 0)
                v[i] = 1;
        }

        if (v[n - 1] == 0)
        {
            ans.push_back({n - 1, n});
            v.pop_back();
            v.pop_back();
            v.push_back(1);
        }
        s.push(v[0]);
        for (int i = 1; i < v.size(); i++)
        {

            if (s.top() == 1 && v[i] == 1)
            {
                s.push(1);
            }
            else
            {
                ans.push_back({s.size(), s.size() + 1});
                s.pop();
                s.push(1);
            }
        }

        ans.push_back({1, s.size()});

        cout << ans.size() << endl;
        for (auto it : ans)
        {
            cout << it.first << " " << it.second << endl;
        }
    }
    return 0;
}