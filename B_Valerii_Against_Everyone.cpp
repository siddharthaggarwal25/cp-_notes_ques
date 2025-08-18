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
        map<int, int> mp;
        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
            if( mp[v[i]] == 2)ans = true ;
        }

        cout<<( ans  ? "YES" :"NO")<<endl;
    }
    return 0;
}