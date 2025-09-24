#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> par, s;
    int maxi = 0;
    int components;
    DSU(int n)
    {
        par.resize(n + 1);
        s.resize(n + 1);
        components = n ;
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
            s[i] = 1;
        }
    }

    int findpar(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = findpar(par[x]);
    }

    void findByUnion(int a, int b)
    {
        int pa = findpar(a);
        int pb = findpar(b);

        if (pa == pb)
            return;

        if (s[pa] > s[pb])
        {
            s[pa] += s[pb];
            par[pb] = pa;
            components--;
            maxi = max(maxi, s[pa]);
        }
        else
        {
            s[pb] += s[pa];
            par[pa] = pb;
            components--;

            maxi = max(maxi, s[pb]);
        }
    }
};
int main()
{
    int n, m;
    cin >> n >> m;

    DSU dsu(n );

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        dsu.findByUnion(a, b);

        cout << dsu.components << " " << dsu.maxi << endl;
    }

    return 0;
}