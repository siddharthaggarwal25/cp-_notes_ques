#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 2);
    map<string, int> mp;
    int ind = 1;
    for (int i = 0; i < n; i++)
    {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        for (auto &x : s1)
        {
            x = tolower(x);
        }
        for (auto &x : s3)
        {
            x = tolower(x);
        }
        if (mp[s3] == 0)
        {
            mp[s3] = ind;
            ind++;
        }
        if (mp[s1] == 0)
        {
            mp[s1] = ind;
            ind++;
        }
        adj[mp[s3]].push_back(mp[s1]);
    }

    for (int i = 1; i <= n + 1; i++)
    {
        cout << i << "------";
        for (auto j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}