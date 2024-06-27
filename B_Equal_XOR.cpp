#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        map<int, int> mp1;
        map<int, int> mp2;

        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            mp1[a]++;
        }
        for (int i = 1; i <= n; i++)
        {
            int b;
            cin >> b;
            mp2[b]++;
        }
        vector<int> ans1;
        vector<int> ans2;
        for (int i = 1; i <= n; i++)
        {
            if (mp1[i] == 2 && (ans1.size() < 2 * k - 1))
            {

                ans1.push_back(i);
                ans1.push_back(i);
            }
            if (mp2[i] == 2 && ans2.size() < 2 * k - 1)
            {
                ans2.push_back(i);
                ans2.push_back(i);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (mp1[i] == 1 && mp2[i] == 1 && (ans1.size() < 2 * k) && (ans1.size() < 2 * k))
            {

                ans1.push_back(i);
                ans2.push_back(i);
            }
        }
        for (int i = 0; i < ans1.size(); i++)
        {
            cout << ans1[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < ans2.size(); i++)
        {
            cout << ans2[i] << " ";
        }
        cout << endl;
    }
    return 0;
}