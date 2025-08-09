#include<bits/stdc++.h>
using namespace std;
int  main (){
      int t ;
       cin>>t ;
       while( t--){
          string s ;
           cin>>s  ;
           int ones = 0  , zeros =0;
           for( int  i =0 ;i<s.size() ; i++){
              if( s[i] =='0')zeros++;
              else ones++;
           }
           int mini  = min (   ones, zeros );
           ones = mini ;
           zeros  = mini;

           int ans = 0 ;
           for ( int i =0  ;i<s.size() ;i++){
             if(s[i] =='1')ones--;
             else zeros--;

             if( ones  <0 || zeros <0){
                ans  = s.size() - i;
                break ;
             }
           }
          
           cout<<ans<<endl;
       }
return 0;
}