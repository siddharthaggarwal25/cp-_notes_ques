#include <bits/stdc++.h>
using namespace std;
vector<int> quali;
vector<int> parent;
vector<int> sz;
vector<int> vis ;

void make_set( int n ){
    for(int i=1  ;i<= n ;i++){
        parent[i] =i;
        sz[i]=1;
    }
}
int  find_set( int x){
    if( parent[x] == x) return x ;
    find_set(parent[x]);
}
void  union_set( int a , int b ){
    int repa = find_set(a);
    int repb = find_set(b);
    if( repa == repb) return;
    if( sz[repb] > sz[repa])  swap( repb , repa);
    parent[repb] =  repa;
    sz[repa] +=sz[repb];
}

int main()
{
    int n;
    cin >> n;
    quali.resize(n + 1);
    parent.resize(n + 1);
    sz.resize(n + 1);
    vis.assign(n+1 , 0 );
    make_set( n );
    for (int i = 1; i <= n; i++)
    {
        cin >> quali[i];
    }
    int m;
    cin >> m;
    vector<pair<int, pair<int, int>>> edges;
    for( int i=0 ;i<m  ;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}}); 
    }
    sort( edges.begin() , edges.end());
    int total =0 ;
    int mst =0 ;
    for( int i=0  ;i<m  ;i++){
        int weight = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        if( find_set( a) == find_set(b) || vis[b] ) continue;
        mst += weight;
        vis[b] = 1;
        total++;
        union_set( a, b );
    }
    if( total != n-1){
        cout<<-1<<endl;
    }else{
        cout<<mst<<endl;
    }
        return 0;
}