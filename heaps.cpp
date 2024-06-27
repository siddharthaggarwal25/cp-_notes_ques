#include<bits/stdc++.h>
using namespace std;
 class heap{
    public  :
     int arr[100];
     int size =0 ;
     
     heap( ){
        int size =0 ;
     }

     void insert( int val ){
        size++;
        arr[size] = val ;
        int index = size;

        while( index >1 ){
            int parentindex = index/2;
            if( arr[parentindex] < arr[index]){
                swap( arr[parentindex] , arr[index]);
            } else{
                break ;
            }
        }
     }

     void print(){
        for( int i=1  ;i<= size ;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
     }
 };

int  main (){
     heap h ;
     h.insert( 1 );
     h.insert( 2);
     h.insert(3);
     h.insert(4);
     h.print();
return 0;
}