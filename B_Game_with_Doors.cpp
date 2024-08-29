#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       
        int q, w, e, r;
        cin >> q >> w >> e >> r;
        vector<int > temp ( 102 ,0);
        int a  = min ( q , w);
        int b = max( q, w);
        for( int i = a ;i<= b  ;i++ ){
            temp[i] ++;
        }
        int c = min( e , r);
        int d = max( e , r);
        for( int i = c  ;i <= d;i++){
            temp[i]++;
        }

        int cnt  =   0 ;
        for( int i=0 ;i< 102  ;i++){
            if( temp[i] == 2) cnt++;
        }
        if( cnt == 0)cnt = 1;
        else if( a== c && b== d )cnt-- ;
        else if( a <c && d< b ) cnt++;
        else if( c<a && b<d) cnt++;
        else if ( a== c || b== d) cnt = cnt ;
        else cnt ++;
        cout<<cnt<<endl;

    }
    return 0;
}