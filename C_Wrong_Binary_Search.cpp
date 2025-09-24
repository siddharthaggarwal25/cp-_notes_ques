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
        string s;
        cin >> s;
        bool ans = true;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                if (cnt == 1)
                    ans = false;
                cnt = 0;
            }
            else
                cnt++;
        }
        if (cnt == 1)
            ans = false;

        if (!ans)
        {
            cout << "NO" << endl;
        }
        else
        {
            vector<int> ans;
            int pre = 0;

            for (int i = 0; i < n; i++)
            {
                if (s[i] == '1')
                {
                    vector<int> temp;
                    for (int j = pre; j <= i - 1; j++)
                    {
                        temp.push_back(j);
                    }

                    if (temp.size() > 1)
                    {
                        int val = temp.back();
                        temp.pop_back();
                        temp.insert(temp.begin(), val);
                        for (int j = 0; j < temp.size(); j++)
                        {
                            ans.push_back(temp[j]);
                        }
                    }

                    ans.push_back(i);
                    pre = i + 1;
                }
            }

            vector<int> temp;
            for (int j = pre; j <= n - 1; j++)
            {
                temp.push_back(j);
            }

            if (temp.size() > 1)
            {
                int val = temp.back();
                temp.pop_back();
                temp.insert(temp.begin(), val);
                for (int j = 0; j < temp.size(); j++)
                {
                    ans.push_back(temp[j]);
                }
            }

            cout << "YES" << endl;
            for (auto it : ans)
                cout << it << " ";
            cout << endl;
        }
    }
    return 0;
}