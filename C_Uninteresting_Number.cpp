#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        int n = str.length();
         long long int sum = 0;
        int twos=0 , threes=0 ;
        for( int i=0 ;i< n ;i++){
            sum += str[i] -'0';
            if( str[i] == '2')twos++;
            else if ( str[i] == '3')threes++;
        }
        bool ans  = false ;
        for( int i=0  ;i<= min( twos  , 10) ;i++ ){
            for( int j =0  ;j<= min ( 10  , threes) ;j++){
                if(  ( sum + i*2 +j*6)% 9 ==0 ) {
                    ans  = true;
                    break ;
                }
            }
            if( ans) break ;
        }

            if( ans ) cout<<"YES"<<endl ;
            else cout<<"NO"<<endl;
        

    }
    return 0;
}