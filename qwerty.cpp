#include <vector>
#include <array>
#include <algorithm>
#include <numeric>

using namespace std;
class Solution
{
public:
    int find(vector<int> &ds, int i)
    {
        if (ds[i] < 0) return i;
        return ds[i] = find(ds, ds[i]);
    }
    int minCostConnectPoints(vector<vector<int>> &ps)
    {
        int n = ps.size(), res = 0;
        vector<int> ds(n, -1);
        vector<array<int, 3>> edges;

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int dist = abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1]);
                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        for (const auto &[dist, i, j] : edges)
        {
            int root_i = find(ds, i);
            int root_j = find(ds, j);

            if (root_i != root_j)
            {
                res += dist;
                ds[root_i] += ds[root_j];
                ds[root_j] = root_i;

                if (ds[root_i] == -n)
                    break;
            }
        }

        return res;
    }
};