#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        vector<int> ans;
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            if (s[low] > s[high])
            {
                ans.push_back(low + 1);
                low++;
            }
            else if (s[low] < s[high])
            {
                ans.push_back(high + 1);
                high--;
            }
            else
            {
                low++;
                high--;
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;

        for( auto it  : ans )cout<<it<<" ";
     
        cout << endl;
    }
    return 0;
}