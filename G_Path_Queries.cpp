#include <bits/stdc++.h>
using namespace std;
#define int long long 
vector<int> parent;
vector<int> sz;
void make_set(int n)
{
    parent.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        sz[i] = 1;
        parent[i] = i;
    }
}

int find_set(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find_set(parent[x]);
}

int union_set(int a, int b)
{
    int repa = find_set(a);
    int repb = find_set(b);
    int ans = sz[repa] * sz[repb];
    if (sz[repa] > sz[repb])
    {
        parent[repb] = repa;
        sz[repa] += sz[repb];
    }
    else
    {
        parent[repa] = repb;
        sz[repb] += sz[repa];
    }
    return ans;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    make_set(n);
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 1; i < n; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({w, {x, y}});
    }
    sort(edges.begin(), edges.end());
    vector<pair<int, int>> query;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        query.push_back({x, i});
    }
    sort(query.begin(), query.end());
    vector<int> ans(m );
    int count = 0;
    int index = 0;
    for (int i = 0; i < query.size(); i++)
    {
        int w = query[i].first;

        while (index < edges.size() && edges[index].first <= w)
        {
            count += union_set(edges[index].second.first, edges[index].second.second);
            index++;
        }
        ans[query[i].second] = count;
    }
    for (int i = 0; i < m; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}