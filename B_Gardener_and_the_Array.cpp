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
        map<int, int> mp;
        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            vector<int> temp;
            for (int j = 0; j < k; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            int cnt = 0;
            for (int j = 0; j < k; j++)
            {
                if (mp[temp[i]] != 0)
                    cnt++;
            }

            if (cnt == k)
                ans = true;
            else
            {
                for (int i = 0; i < k; i++)
                {
                    mp[temp[i]]++;
                }
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}