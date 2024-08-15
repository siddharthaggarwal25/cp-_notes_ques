#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int m;
        cin >> m;
        while (m--)
        {
            string s;
            cin >> s;
            if (s.size() == n)
            {
                unordered_map<char, int> mp;
                unordered_map<int, char> mp2;
                bool flag = true;
                for (int i = 0; i < n; i++)
                {
                    if (mp.find(s[i]) == mp.end() && mp2.find(arr[i])==mp2.end())
                    {
                        mp[s[i]] = arr[i];
                        mp2[arr[i]] = s[i];
                    }
                    else if(mp.find(s[i]) == mp.end() || mp2.find(arr[i])==mp2.end() || mp[s[i]] != arr[i]  || mp2[arr[i]] != s[i]){
                        flag = false ;
                        break ;
                    } 
                   
                }
                if (flag)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
