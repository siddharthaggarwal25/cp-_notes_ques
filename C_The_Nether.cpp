#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, vector<int>, greater<>> mp;
        int cur = 1;

        for (int i = 1; i <= n; i++)
        {
            cout << "? " << i << " " << n << " ";
            for (int j = 1; j <= n; j++) 
            {
                cout << j << " ";
            }
            cout << endl;
            cout.flush();

            int x;
            cin >> x;
            cur = max(cur, x);
            mp[x].push_back(i);
        }

        vector<int> ans;
        int node = mp[cur][0];
        ans.push_back(node);
        cur--;

        while (cur >= 1)
        {

            for (auto it : mp[cur])
            {
                cout << "? " << node << " " << 2 << " " << node << " " << it << endl;
                cout.flush();

                int temp;
                cin >> temp; 
                if (temp == 2)
                {
                    ans.push_back(it);
                    node = it;
                    break;
                }
            }
            cur--;
        }

        cout << "! " << ans.size() << " ";
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
        cout.flush();
    }
    return 0;
}
