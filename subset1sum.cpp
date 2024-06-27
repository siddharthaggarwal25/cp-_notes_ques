#include <bits/stdc++.h>
using namespace std;
void subset(int index, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);
    for (int i = index; i < arr.size(); i++)
    {
        if (i != index && arr[i] == arr[i - 1])  continue;
        ds.push_back(arr[i]);
        subset(i + 1, arr, ds, ans);
        ds.pop_back();
    }
}
int main()
{
    vector<vector<int>> ans;
    vector<int> arr = {1, 2, 3};
    vector<int> ds;
    subset(0, arr, ds, ans);
   for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout<<ans.size();
    return 0;
}