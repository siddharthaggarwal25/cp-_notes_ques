#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, x;
int count(int len , vector<  int > & dp ) 
{
    if (len == 0)
        return 0;
    if (len < 0)
        return -1e9;
     if( dp[len]  != -1 ) return dp[len ];   

    int first = 1 + count(len - a , dp );
    int second = 1 + count(len - b  , dp);
    int third = 1 + count(len - c , dp );

    return  dp[len]=  max(first, max(second, third));
}
int main()
{
    cin >> n >> a >> b >> c;
    x = min(a, min(b, c));
    vector< int > dp( n+1 , -1  );
    cout << count(n , dp ) << endl;
    return 0;
}