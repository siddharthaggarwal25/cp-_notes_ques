        #include <bits/stdc++.h>
        using namespace std;

        bool dfs(int node, int parent, vector<int> &vis, vector<set<int>> &adj)
        {

            vis[node] = 1;
            bool temp = false;
            for (auto child : adj[node])
            {
                if (child == parent)
                    continue;
                if (vis[child] == 1)
                    return true;
                temp = temp | dfs(child, node, vis, adj);
            }
            return temp;
        }
        int main()
        {
            int t;
            cin >> t;
            while (t--)
            {
                int n;
                cin >> n;
                vector<set<int>> adj(n + 1);
                for (int i = 1; i <= n; i++)
                {
                    int x;
                    cin >> x;
                    adj[i].insert(x);
                    adj[x].insert(i);
                }

                int cnt = 0;
                int cycle = 0;
                vector<int> vis(n + 1, 0);

                for (int i = 1; i <= n; i++)
                {
                    if (vis[i] == 0)
                    {

                        if (dfs(i, -1, vis, adj))
                            cycle++;
                        else
                            cnt++;
                    }
                }

                int ans;
                if (cycle != 0)
                {
                    if (cnt != 0)
                    {
                        cout << cycle + 1 << " " << cycle + cnt << endl;
                    }
                    else
                    {
                        cout << cycle << " " << cycle + cnt << endl;
                    }
                }
                else
                {
                    cout << 1 << " " << cnt << endl;
                }
            }
            return 0;
        }