#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> color(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> color[i];
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<vector<int>> colornode(100000);
    for (int i = 1; i <= n; i++)
    {
        colornode[color[i]].push_back(i);
    }
    int ans = 0;
    int col = -1 ;
    for (int i = 1; i < 100000; i++)
    {
        if (colornode[i].size() > 0)
        {
            set<int> st;
            for (auto nodes : colornode[i])
            {
                for (auto child : adj[nodes])
                {
                   if( color[child] != color[nodes]) st.insert(color[child]);
                }
            }
            int a = st.size();
            if( a > ans ){
                ans = a ;
                col = i ;
            }
        }
    }
  if( col == -1)cout<<color[1]<<endl;
   else cout<<col<<endl;

    return 0;
}