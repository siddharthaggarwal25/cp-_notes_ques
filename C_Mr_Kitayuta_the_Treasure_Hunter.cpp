#include <bits/stdc++.h>
using namespace std;
int a = 30010 ;
map<int, int> mp;
vector< vector<int >> dp( a, vector< int  >( 2000 , -1 ));    
int gems(int s, int l )
{
   int res =0 ;
   int v ;
   for( int i= -1  ;i<2 ;i++){
    v =   s +i +l;
    if( v> 30000 || v <=s ) continue;
     res = max( res , gems( v  , l+i  ))
   }
   return res ;
}
int main()
{
    int n, d;
    cin >> n >> d;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    cout << gems(d, d)  << endl;

    return 0;
}