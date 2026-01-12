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
        string s;
        cin >> s;

        int ans = 0;
        int safeMove = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                safeMove --;
            }
            else
            {
                 if( safeMove > 0){
                     safeMove = k-1;
                 }else{
                     safeMove = k-1;
                     ans++;
                 }

            }
        }

        cout << ans << endl;
    }
    return 0;
}