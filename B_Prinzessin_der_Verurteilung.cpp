#include <bits/stdc++.h>
using namespace std;

bool isthere(string &s, string &temp, int n)
{
      for( int i= 0 ;i<n-temp.size()+1  ;i++){ 
        bool check = true ;
          for ( int j=0 ;j<temp.size();j++){
             if( s[i + j ]  != temp[j] )check = false;
          }
          if( check)return check ;
      }
      return false ;
}
void solve(string &s, int n)
{
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 26; j++)
        {
            for (int k = 0; k < 26; k++)
            {
                string temp = "";
                if (i != -1)
                    temp += 'a' + i;
                if (j != -1)
                    temp += 'a' + j;
                temp += 'a' + k;
                if (!isthere(s, temp, n))
                {
                    cout << temp << endl;
                    return;
                }
            }
        }
    }
}
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
        solve(s, n);
    }
    return 0;
}