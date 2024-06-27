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
    string a, b, c;
    cin >> a >> b >> c;
    bool check = false;
    for (int i = 0; i < n; i++)
    {
      if ((a[i] != c[i] && b[i] != c[i]))
      {
        check = true;
        break;
      }
    }
    if (check)
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