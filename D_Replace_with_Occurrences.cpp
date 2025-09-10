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
        vector<int> ans(n);
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]].push_back(i);
        }

        bool temp = true;
        int number = 1;

        for (auto &it : mp)
        {
            int size = it.first;

            if (it.second.size() % it.first != 0)
            {
                temp = false;
                cout << -1 << endl;
                break;
            }

            int curSize = size;
            for (auto ind : it.second)
            {
                ans[ind] = number;
                curSize--;
                if (curSize == 0)
                {
                    curSize = size;
                    number++;
                }
            }
        }

        if (temp)
        {
            for (int i = 0; i < n; i++)
                cout << ans[i] << " ";
            cout << endl;
        }
    }
    return 0;
}