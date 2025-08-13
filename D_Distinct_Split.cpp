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
        string s;
        cin >> s;
        vector<int> a(26), b(26);
        int cnt = 0, cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[s[i] - 'a'] == 0)
                cnt++;
            mp[s[i] -'a']++;
        }

        int ans = cnt;
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]--;
            if (mp[s[i]] == 0)
                cnt--;
            if (mp2[s[i]] == 0)
                cnt2++;
            mp2[s[i]]++;

            ans = max(ans, cnt + cnt2);
        }
        cout << ans << endl;
    }
    return 0;
}