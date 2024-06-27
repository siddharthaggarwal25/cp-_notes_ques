#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (i == 0 || v.back() != x)
            {
                v.push_back(x);
            }
        }

            int num = 0;

            for (int i = 0; i <= v.size()-1; i++)
            {
               if((i==0 || v[i-1]>v[i]) && (i==v.size()-1||v[i]<v[i+1]))
               num++;
            }

            if (num == 1)
            {

                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        
    }
    return 0;
}