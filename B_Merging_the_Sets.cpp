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
        vector<vector<int>> sets(n);
        vector<int> fre(m + 1, 0);
        int diff = 0;
        for (int i = 0; i < n; i++)
        {
            int l;
            cin >> l;
            for (int j = 0; j < l; j++)
            {
                int x;
                cin >> x;
                if (fre[x] == 0)
                    diff++;
                fre[x]++;
                sets[i].push_back(x);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            bool temp = true;
            for (auto &it : sets[i])
            {
                fre[it]--;
                if (fre[it] == 0)
                    temp = false;
            }

            if (temp)
                cnt++;

            for (auto &it : sets[i])
            {
                fre[it]++;
            }
        }

        if (diff != m || cnt <= 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}