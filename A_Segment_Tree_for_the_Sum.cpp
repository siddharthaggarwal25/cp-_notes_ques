#include<bits/stdc++.h>
using namespace std;
int n , m ;
vector< int > arr , seg;


void build( int id , int l , int r ){
     if((r-l) ==1  ){
        seg[id] = arr[r];
        return ;
     }

     int mid  = ( l+r)/2;
     build( 2*id , l , mid );
     build( ( 2*id) +1 , mid  , r );
     seg[id] = seg[2*id] + seg[2*id  +1 ];
}

void modify( int pos , int val , int id  , int l  , int r ){
    if( r-l == 1){
        seg[id] = val;
        return ;
    }
    int mid  = ( l+r)/2;
    if( pos < mid){
        modify( pos , val, 2*id  , l ,mid );

    }else{
        modify( pos, val  , 2*id +1  , mid , r );
    }
    seg[id] = seg[2*id ] + seg[2*id +1];
}

int query (  int x , int y  , int id , int l , int r ){
    if( l>=x && y<= r){
        return seg[id];
    }else if ( l>=y || x<= r ){
        return 0 ;
    }else{
        int mid = ( l+r)/2;
        return query( x , y , 2*id , l , mid ) + query( x , y , 2*id +1  , mid  , r);
    }
}
int  main (){
    cin>>n>>m ;
    arr.resize( n+1 );
    seg.resize( (4*n)+1);
    for( int i=1  ;i<=n  ;i++){
        cin>>arr[i];
    }
    build( 1 , 0 , n );
    modify( 1 , 1 , 1 , 0 , n );
    for( int i=1  ;i<=(4*n) ;i++) cout<<seg[i]<<" ";
    cout<<endl;

    while( m--){
        int a , b  , c ;
        cin>>a>>b>>c ;
        if( a== 1) {
            modify(  b , c   ,1 , 0 , n );
        }else{
            cout<<query( b ,c,  1 , 0 , n )<<endl;
        }
    }
     
return 0;
}