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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        int k;
        cin >> k;
        map<int, int> mp;
        int check;
        while (k--)
        {
            int x;
            cin >> x;
            mp[x]++;
            if (k == 0)
            {
                check = x;
            }
        }
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            int ind = i;
            int val = b[i];
            if (val == a[i])
            {
                continue;
            }
            else
            {
                if (mp[val] != 0)
                {
                    mp[val]--;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if (mp[check] == 0)
        {
            if (flag)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            bool f = 0;
            for (int i = 0; i < n; i++)
            {
                if (check == b[i])
                {
                    f = true;
                }
            }
            if (f )cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}