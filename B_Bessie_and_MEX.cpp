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
        vector<int> v(n);
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            s.insert(i);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            int x;
            if (v[i] < 0)
            {
                x = (*s.begin()) - v[i];
            }
            else
            {
                x = *s.begin();
            }
            ans[i] = x;
            s.erase(x);
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}