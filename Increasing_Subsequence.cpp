#include <bits/stdc++.h>
using namespace std;
int count(int ind, int preindex, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == arr.size())
        return 0;
    if (dp[ind][preindex + 1] != -1)
        return dp[ind][preindex + 1];

    int nottake = count(ind + 1, preindex, arr, dp);
    int take = 0;
    if (preindex == -1 || arr[ind] > arr[preindex])
        take = 1 + count(ind + 1, ind, arr, dp);
    return dp[ind][preindex + 1] = max(take, nottake);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int len = 1;
    vector<int> temp;
    temp.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
            len++;
        }else{
            int ind = lower_bound( temp.begin() , temp.end() , arr[i]) - temp.begin();
            temp [ind] = arr[i];
        }
    }
    cout<<len<<endl;
    return 0;
}