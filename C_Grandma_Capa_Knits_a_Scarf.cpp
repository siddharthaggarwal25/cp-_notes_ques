#include <bits/stdc++.h>
using namespace std;

bool is_palidrome( vector<char> & temp){
     int n  = temp.size();

     int low  =0 ;
     int high = n-1 ;
     while( low <high){
        if( temp[low] == temp[high]){
            low++;
            high--;

        }else{
            return false;
        }
     }
     return true ;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        vector<vector<char>> v(26);

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < 26; j++)
            {
                if (s[i] - 'a' == j)
                    continue;
                v[j].push_back(s[i]);
            }
        }

        int ans = 1e9;

        for (int i = 0; i < 26; i++)
        {
            if (is_palidrome(v[i]))
            {
                char toRemove = 'a' + i;

                int low = 0;
                int high = n - 1;
                int cnt = 0;
                while (low < high)
                {
                    if (s[low] == s[high])
                    {
                        low++;
                        high--;
                    }
                    else if (s[low] == toRemove)
                    {
                        low++;
                        cnt++;
                    }
                    else
                    {
                        high--;
                        cnt++;
                    }
                }
                
                ans = min(ans, cnt);
            }
        }

        cout << (ans == 1e9 ? -1 : ans )<< endl;
    }
    return 0;
}