#include <bits/stdc++.h>
using namespace std;
int count(int i, int j, string s1, string s2 , vector< vector< int >>  & dp )
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
        if( dp[i][j] != -1 ) return dp[i][j];
    if (s1[i] == s2[j])
        return dp[i][j] = count(i - 1, j - 1, s1, s2 , dp);
    return  dp[i][j] =  1 + min(count(i - 1, j, s1, s2 , dp), min(count(i, j - 1, s1, s2 , dp ), count(i - 1, j - 1, s1, s2 , dp 
    )));
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    vector< vector< int >>  dp( n+1 , vector< int >  ( m+1 , -1 ) );
    cout << count(n - 1, m - 1, s1, s2  , dp );
    return 0;
}