
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        char s;
        cin >> s;
        vector<pair<int, char>> v;
        for (int i = 0; i < 2 * n; i++)
        {
            string str;
            cin >> str;
            v.push_back({char(str[1]), str[0]});
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < 2 * n; i++)
        {
            cout << v[i].first << v[i].second << " ";
        }
        cout << endl;
        ;
    }
    return 0;
}