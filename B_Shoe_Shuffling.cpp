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
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (i == 0)
            {
                v.push_back({x, 1});
            }
            else
            {
                if (x == v.back().first)
                {
                    v.back().second++;
                }
                else
                {
                    v.push_back({x, 1});
                }
            }
        }
        int check = true;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].second == 1)
            {
                check = false;
                break;
            }
        }
        if (!check)
        {
            cout << -1 << endl;
        }
        else
        {

            int count = 0;

            for (int i = 0; i < v.size(); i++)
            {
                cout << count + v[i].second << " ";
                for (int j = 1; j < v[i].second; j++)
                {
                    cout << count + j << " ";
                }
                count += v[i].second;
            }
            cout << endl;
        }
    }
    return 0;
}