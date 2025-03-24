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
        vector<int> ans(  n , x  );
         int temp  =0 ;
         bool flag = true ;
        for( int i =0  ;i< n-1  ;i++){

            if( (( temp| i) & x )  == ( temp|i)){
                  temp = temp | i ;
                   ans [i] = i ;
            }else {
                flag  =false;
                  break ;
            
            }
        }

        if( flag && ( (temp| (n-1 ))== x)){
             ans [ n-1] = n-1;
        }


        for( auto an : ans )cout<<an<<" ";
        cout<<endl;
    }

    return 0;
}