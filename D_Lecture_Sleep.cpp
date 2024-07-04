#include<bits/stdc++.h>
using namespace std;
int solve ( int ind , int flag  , vector<int >&theorms , vector<int > & sleep){
         
         int val =  ;
        if( sleep[ind]==0) val= theorms[ind] + solve( ind +1 , flag , theorms , sleep);
        else  if( flag  == 0) val = prefix[ind]  + solve( ind+k , 1 , theorms , sleep);
        else  solve( ind+1  , flag , )
}
int  main (){
     int n , k;
     cin>>n>>k ;
     vector<int > theorms( n), sleep( n );
     for( int i=0 ;i< n  ;i++)cin>>theorms[i];
     for( int i=0 ;i< n  ;i++)cin>>sleep[i];
      vector< int > prefix( n);
      for( int i=0 ;i<n ;i++){
          for(int j=i   ;j < min ( n , i+k) ;j++){
             prefix[i] += theorms[j];
          }
      }

return 0;
}