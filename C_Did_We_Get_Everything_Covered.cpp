#include <bits/stdc++.h>
using namespace std;
int main()
{
      int t;
      cin >> t;
      while (t--)
      {
            int n, k, m;
            cin >> n >> k >> m;

            string s;
            cin >> s;
            set<char> st;
            string ans = "";
            for (int i = 0; i < m; i++)
            {
                  if (ans.size() == n)
                        break;
                  st.insert(s[i]);
                  if (st.size() == k)
                  {
                        st.clear();
                        ans += s[i];
                  }
            }
            if (ans.size() == n)
            {
                  cout << "YES" << endl;
            }
            else
            {
                  cout << "NO" << endl;
                  char miss;
                  for (int j = 0; j < k; j++)
                  {
                        char ch = char('a' + j);
                        if (st.count(ch) == 0){
                              miss = ch;
                              break;
                        }
                  }
                  while (ans.size() < n)
                        ans.push_back(miss);
                  cout << ans << endl;
            }
      }
      return 0;
}