#include <bits/stdc++.h>
using namespace std;
void precompute(const string &S, vector<vector<bool>> &isPalindrome)
{
    int n = S.size();
    for (int i = 0; i < n; ++i)
    {
        isPalindrome[i][i] = true;
    }
    for (int len = 2; len <= n; ++len)
    {
        for (int i = 0; i <= n - len; ++i)
        {
            int j = i + len - 1;
            if (S[i] == S[j])
            {
                if (len == 2)
                {
                    isPalindrome[i][j] = true;
                }
                else
                {
                    isPalindrome[i][j] = isPalindrome[i + 1][j - 1];
                }
            }
        }
    }
}
int countGoodTriplets(const string &S)
{
    int n = S.size();
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
    precompute(S, isPalindrome);
    vector<int> dpLeft(n, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (isPalindrome[j][i])
            {
                dpLeft[i]++;
            }
        }
        if (i > 0)
        {
            dpLeft[i] += dpLeft[i - 1];
        }
    }
    vector<int> dpRight(n, 0);
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i; j < n; ++j)
        {
            if (isPalindrome[i][j])
            {
                dpRight[i]++;
            }
        }
        if (i < n - 1)
        {
            dpRight[i] += dpRight[i + 1];
        }
    }
    int goodTriplets = 0;
    for (int i = 1; i < n - 1; ++i)
    {
        for (int j = i; j < n - 1; ++j)
        {
            if (isPalindrome[i][j])
            {
                goodTriplets += dpLeft[i - 1] * dpRight[j + 1];
            }
        }
    }
    return goodTriplets;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {  
        int n ;
        cin>>n ;
        
        string S;
        cin >> S;
        cout << countGoodTriplets(S) << endl;
    }
    return 0;
}
