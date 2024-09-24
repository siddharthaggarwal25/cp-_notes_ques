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

        map<char, int> mp;
        for (auto it : s)
        {
            mp[it]++;
        }

        string temp = "";
        while (!mp.empty())
        {
            for (auto it = mp.begin(); it != mp.end();)
            {
                char cur = it->first;
                temp += cur;
                it->second--;

                if (it->second == 0)
                {
                    it = mp.erase(it); 
                }
                else
                {
                    ++it;
                }
            }
        }
        cout << temp << endl;
    }
    return 0;
}
