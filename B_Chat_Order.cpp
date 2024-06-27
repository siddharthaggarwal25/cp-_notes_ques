#include<bits/stdc++.h>
using namespace std;
int  main (){
   int n;
    cin>>n;
    map<string,int> chats;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        chats[s]=i;
    }
 
    map<int,string> orders;
    for(auto c : chats)
    {
        orders[c.second]=c.first;
    }
    for(auto it = orders.rbegin(); it !=orders.rend() ;it++)
    {
        cout<<it->second<<endl;
    }
     
return 0;
}