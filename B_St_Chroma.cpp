#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector< int > temp( n) ;
        for( int i= 0 ;i< n ; i++)temp[i] = i ;

        int curr = 1e9 ;
        for( int i =0 ;i< n  ;i++){
             if( i == x )curr = i;
             else cout<<i <<" ";
        }
        if( curr != 1e9)cout<<curr<<" ";
        cout<<endl;

    }
    return 0;
}