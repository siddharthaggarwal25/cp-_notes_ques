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
        vector<int> v(n);
        v[0] = -1;
        for (int i = 1; i < n; i++)
        {
            cin >> v[i];
        }
        int element = n;
        for (int i = 1; i < n; i++)
        {
            int index = find(v.begin() + 1, v.end(), i) - v.begin();
            if (index == v.end() - v.begin())
            {
                element = i;
                break;
            }
        }


        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int score = 0;
            score += max(element, i);
            for (int j = 1; j < n; j++)
            {
                if (j < i)
                {
                    score += max(v[j], j);
                }
                else
                {
                    score += max(v[j], j + 1);
                }
            }
            ans = max(ans, score);
         
        }
        cout << ans << endl;
    }
    return 0;
}