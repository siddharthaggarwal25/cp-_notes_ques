#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> ind(m);
        for (int i = 0; i < m; i++)
        {
            cin >> ind[i];
            ind[i]--;
        }
        string c;
        cin >> c;
        sort(c.begin(), c.end());
        cout << c << endl;
    }
    return 0;
}