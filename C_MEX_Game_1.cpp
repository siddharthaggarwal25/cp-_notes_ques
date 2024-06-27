#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,b=0;
        cin >> n;
        int max_ = 0;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {  int a ;
            cin >> a;
            if (a > max_)
            {
                max_ = a;
            }
            mp[a]++;
        }

        int ans = max_ + 1;
        for (int i = 0; i <= max_; i++)
        {
            /* code */if(mp[i]==1){
                b=i;
                break;
            }
        }
        if(mp[0]==0){
            cout << 0 << endl;
        }else{
        for (int i = 1; i <= max_; i++)
        {
            if (mp[i] < 2 && b!=i)
            {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
    
}}