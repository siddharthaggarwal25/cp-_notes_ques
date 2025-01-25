#include <bits/stdc++.h>
using namespace std;
// #define int long long 
bool solve()
{
      int n, m , x;
      cin >> n >> m;
      priority_queue<int> p, q;
      for (int i = 0; i < n; i++) cin >> x, p.push(x);
      for (int i = 0; i < m; i++)cin >> x, q.push(x);
      while (!p.empty() && !q.empty())
      {
            if (p.top() > q.top() || p.size() < q.size())
                  return false ;
            if (p.top() == q.top())
            {
                  p.pop();
                  q.pop();
                  continue;
            }
            x = q.top();
            q.pop();
            q.push( x/2);
            q.push((x+1 )/2);
      }
      if( p.empty() && q.empty())return true;
      return false ;
}
int32_t  main()
{
      int t;
      cin >> t;
      while (t--)
      {
            if (solve())
                  cout << "YES" << endl;
            else
                  cout << "NO" << endl;
      }
      return 0;
}