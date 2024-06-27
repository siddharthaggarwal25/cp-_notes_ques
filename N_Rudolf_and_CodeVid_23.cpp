#include <bits/stdc++.h>
using namespace std;
#define int long long
int binaryToDecimal(string str)
{
    int sz = str.size();
    reverse(str.begin(), str.end());
    int ans = 0;
    for (int k = 0; k < sz; k++)
    {
        if (str[k] == '1')
        {
            ans += (1 << k);
        }
    }
    return ans;
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int start = binaryToDecimal(s);
        vector<array<int, 3>> edges(m);
        for (int i = 0; i < m; i++)
        {
            int a;
            string good, bad;
            cin >> a >> good >> bad;
            edges[i][0] = a;
            edges[i][1] = binaryToDecimal(good);
            edges[i][2] = binaryToDecimal(bad);
        }
        vector<int> distance(1 << 10, 1e18);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        distance[start] = 0;
        pq.push({0, start});
        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (int i = 0; i < m; i++)
            {
                int bad = node | edges[i][2];
                int good = edges[i][1];
                int fin = 0;
                for (int j = 0; j < 11; j++)
                {
                    if (bad & (1 << j))
                    {
                        if (!(good & (1 << j)))
                        {
                            fin = fin + (1 << j);
                        }
                    }
                }
                // cout << bad << endl;
                // cout << good << endl;
                // cout << fin << endl;
                // cout << endl;
                // cout << endl;

                if (distance[fin] > dis + edges[i][0])
                {
                    distance[fin] = dis + edges[i][0];
                    pq.push({distance[fin], fin});
                }
            }
        }

        if (distance[0] == 1e18)
            distance[0] = -1;

        cout << distance[0] << endl;
    }
    return 0;
}