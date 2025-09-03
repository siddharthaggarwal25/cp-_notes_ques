#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> edge;
    vector<int> degree(n + 1, 0);
    bool check = false;
    int  temp;
    for (int i = 1; i <= n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;

        if (degree[u] == 3 || degree[v] == 3)
        {
            check = true;
            if (degree[u] == 3)
                temp = u;
            else
                temp = v;
        };
        edge.push_back({u, v});
    }

    int cnt1 = 0 ;
    int cnt2 = n-2;
    if (check)
    {
        for( auto it  : edge ){
             if( it.first == temp || it.second == temp ){
                cout<<cnt1<<endl;
                cnt1++;
             }else{
                cout<<cnt2<<endl;
                cnt2--;
             }
        }
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            cout << i << endl;;
        }
    }

    return 0;
}