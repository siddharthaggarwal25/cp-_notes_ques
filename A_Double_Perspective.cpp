#include <bits/stdc++.h>
using namespace std;
class DSU
{
public:
    vector<int> parent, size;
    DSU(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findPar(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = findPar(parent[x]);
    }

    void unionBySize(int a, int b)
    {
        int para = findPar(a);
        int parb = findPar(b);

        if (para == parb)
            return;
        if (size[para] > size[parb])
        {
            size[para] += size[parb];
            parent[parb] = para;
        }
        else
        {
            swap(para, parb);
            size[para] += size[parb];
            parent[parb] = para;
        }
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].first >> v[i].second;
        }
        DSU dsu(2 * n + 1);

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {

            if (dsu.findPar(v[i].first) != dsu.findPar(v[i].second))
            {
                dsu.unionBySize(v[i].first, v[i].second);
                ans.push_back(i + 1);
            }
        }

        cout << ans.size() << endl;
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}