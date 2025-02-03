#include <bits/stdc++.h>
using namespace std;
#define int long long 
int solve(vector<int> v)
{
    if (v.size() == 1)
        return v[0];

    int sum = accumulate(v.begin(), v.end(), 0LL);
    vector<int> t1, t2;
    for (int i = 0; i < v.size() -1; i++)t1.push_back( v[i+1] - v[i] );
    reverse( v.begin() , v.end());
    for (int i = 0; i < v.size() -1; i++)t2.push_back( v[i+1] - v[i] );
    int sum1 = accumulate( t1.begin() ,t1.end() , 0LL);
    int sum2 = accumulate( t2.begin() ,t2.end() , 0LL);
    if( sum1 > sum2){
        return max( sum  , solve( t1));
    }
    return max( sum,  solve( t2 ));
    
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> temp;
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int ans = solve(v);
        cout << ans << endl;
    }
    return 0;
}