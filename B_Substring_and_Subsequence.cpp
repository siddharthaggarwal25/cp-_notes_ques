#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        int x = a.size();
        int y= b.size();
        int ans  =0 ;
        for( int  i=0 ;i<   y  ;i++){
            int temp  =0 ;
            int temp2 = i ;
            for( int j=0 ;j<x ;j++){
                if( b[temp2] == a[j]){
                    temp++;
                    temp2++;
                } 
                if(temp == y)break; 
            }
        ans  = max( ans  , temp  );
        }
        cout<<x +y - ans<<endl;


    }
    return 0;
}