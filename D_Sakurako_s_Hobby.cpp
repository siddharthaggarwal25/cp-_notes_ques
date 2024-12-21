#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
vector<vector<int>> adj;
string s;
void dfs(int index, vector<int> &vis, vector<int > & parent ,  int &count , int head   )
{
    if (vis[index] ==1 )return;
    vis[index] = 1;
    parent[index] = head ;
    if (s[index] == '0')count++;
    for (auto child : adj[index])
    {
        if (vis[child] ==0 )
        {
            dfs(child, vis, parent  , count  , head ) ;
        }
    }
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vec.clear();
        adj.clear();
        vec.resize(n);
        adj.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
            vec[i]--;
            adj[i].push_back(vec[i]);
        }
        cin >> s;
        vector<int> ans(n );
        vector<int > parent( n , 0 );
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {    
            if(vis[i])continue ;
            int count = 0;
            dfs(i, vis,parent ,  count , i );
            ans[i] = count ;
        }
        for (int i=0 ;i< n ;i++)
        {
            cout<<ans[parent[i]] <<" ";
        }
        cout << endl;
    }
    return 0;
}