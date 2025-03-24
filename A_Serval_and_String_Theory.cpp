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

        if (k == 0)
        {
            string temp = s;
            reverse(temp.begin(), temp.end());
            if (s < temp)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            bool check = false;
              for( int i =0 ; i< n  ;i++){
                 if( s[i] != s[0]) check = true  ;
              }

              if( check ) cout<<"YES"<<endl;
              else cout<<"NO"<<endl;

        }
    }
    return 0;
}