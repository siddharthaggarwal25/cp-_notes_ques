#include<bits/stdc++.h>
using namespace std;
int  main (){
     int arr[10];
     arr[0]=1;
     arr[1]=2;
     arr[2]=2;
     arr[3]=3;
     arr[4]=3;
     arr[5]=3;
     arr[6]=4;
     arr[7]=4;

     int index1= lower_bound(arr ,arr +8 , 2)-arr;
     int index2= upper_bound(arr ,arr +8 , 2)-arr;
     
     cout<<index1<<" "<<index2;


return 0;
}