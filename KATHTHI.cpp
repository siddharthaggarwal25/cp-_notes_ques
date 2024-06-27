#include <bits/stdc++.h>
using namespace std;

bool isValid(int x , int y , int n , int m ){
    if( x>=0 && y>=0 && x<n && y<m){
        return true ;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int xi[] = {1, -1, 0, 0};
        int yi[] = {0, 0, 1, -1};
        deque<pair<int, int>> dq;
        dq.push_back({0, 0});

        vector<vector<int>> cost(n, vector<int>(m, 100000000));
        cost[0][0] = 0;
        while (!dq.empty())
        {
            int x = dq.front().first;
            int y = dq.front().second;

            dq.pop_front();
            for (int i = 0; i < 4; i++)
            {
                int newx = x + xi[i];
                int newy = y + yi[i];

                if (isValid(newx, newy, n, m))
                {
                    if ((v[newx][newy] == v[x][y]) && cost[newx][newy] > cost[x][y])
                    {
                        cost[newx][newy] = cost[x][y];
                        dq.push_back({newx, newy});
                    }
                    else if (cost[newx][newy] > cost[x][y] + 1)
                    {
                        cost[newx][newy] = cost[x][y] + 1;
                        dq.push_front({newx, newy});
                    }
                }
            }
        }
        cout<< cost[n-1][m-1]<<endl;
        
    }
    return 0;
}