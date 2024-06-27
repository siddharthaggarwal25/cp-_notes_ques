#include<bits/stdc++.h>
using namespace std;
int  main (){
     int t;
     cin>>t ;
     while( t--){
         int n , m ;
         cin>>n>>m ;
         vector< vector<char >>  grid( n  , vector< char > ( m ));
         for( int i=0 ;i< n ;i++){
            for( int j=0 ;j< m  ;j++){
                cin>>grid[i][j];
            }
         }
         int row =0 ;
         int cur =0 ;
         for( int i=0 ;i< n  ;i++){
            int temp = 0 ;
            for( int  j=0 ;j< m  ;j++){
                if( grid[i][j] == '#'){
                    temp++;
                }
            }
            if(temp > cur ){
                row = i ;
                cur = temp ;
            }
         }
         int col =0 ;
          cur =0 ;
         for( int i=0 ;i< m  ;i++){
            int temp = 0 ;
            for( int  j=0 ;j< n  ;j++){
                if( grid[j][i] == '#'){
                    temp++;
                }
            }
            if(temp > cur ){
                col = i ;
                cur = temp ;
            }
         }

         cout<<row+1 <<" "<<col+1<<endl;
     }
return 0;
}