#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, n, m;
        cin >> k >> n >> m;
        int arr[n];
        int arr2[m];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int j = 0; j < m; j++)
        {
            cin >> arr2[j];
        }
        vector<int> v;
        int pos1=0;
        int pos2=0;
        bool check =true;
   while ( pos1!=n || pos2 !=m ){
     if( pos1 !=n &&  arr[pos1]==0){
        v.push_back(0);
        k++;
        pos1++;
     }else if( pos2 !=m && arr2[pos2]==0){
        v.push_back(0);
        k++;
        pos2++;
     }else if( pos1 !=n && arr[pos1]<=k){
        v.push_back(arr[pos1]);
        pos1++;
     }else if( pos2 !=m && arr2[pos2]<=k){
        v.push_back(arr2[pos2]);
        pos2++;
     }else{
        cout<<-1<<endl;
        check =false;
        break;
     }
   }
   if( check){
    for(int i=0 ;i< v.size() ;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
   }

   
      
    }
    return 0;
}