#include <bits/stdc++.h>
using namespace std;
int n, m;
string h, v;
vector<int > order;
void dfs( int node , vector< int > & vis) {

    vis[node] =1 ;
    int row = node/(m) ;
    int col = node%( m)  ;

    if( h[row] == '>' ){
      if( node+1 <(n*m)  && !vis[node+1])  dfs( node + 1 , vis );
    }else{
       if( node-1 >=0 &&  !vis[node -1]) dfs( node-1 ,  vis); 
    }

    if( v[col] == '^'){
        if( node-m >=0 && !vis[node-m]) dfs( node - m , vis);
    }else{
        if( node+m < ( n*m) && !vis[node+m] ) dfs( node+m  , vis);
    }
    order.push_back( node);

}
void dfs2( int node , vector< int > & vis) {

    vis[node] =1 ;
    int row = node/(m) ;
    int col = node%( m)  ;

    if( h[row] == '<' ){
      if( node+1 <(n*m)  && !vis[node+1])  dfs( node + 1 , vis );
    }else{
       if( node-1 >=0 &&  !vis[node -1]) dfs( node-1 ,  vis); 
    }

    if( v[col] == 'v'){
        if( node-m >=0 && !vis[node-m]) dfs( node - m , vis);
    }else{
        if( node+m < ( n*m) && !vis[node+m] ) dfs( node+m  , vis);
    }

}
 
int main()
{
    cin >> n >> m;
    cin >> h >> v;
    vector<int> vis(n * m, 0);
    dfs( 0 , vis);
    reverse( order.begin() , order.end());
    vector< int >  vis2(n*m ,0  );
    int cnt= 0 ;
    for( auto el : order){
        cnt ++;
      if(!vis2[el])   dfs2( el , vis2);
    }
    if( cnt ==1  )cout<<"YES"<<endl;
    else{
        cout<<"NO"<< cnt <<endl;
    }

        return 0;
}