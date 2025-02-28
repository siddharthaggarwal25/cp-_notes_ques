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
        vector<int> freq;
        map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }

        for (auto it : mp)
        {
            freq.push_back(it.second);
        }
        sort(freq.begin(), freq.end());
        int ans = freq.size();
        for (int i = 0; i < freq.size() - 1; i++)
        {
            if (freq[i] <= k)
            {
                ans--;
                k -= freq[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}