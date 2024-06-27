#include <bits/stdc++.h>
using namespace std;
vector<int> parent(200001);
vector<int> size_(200001);
void make_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        size_[i] = 1;
    }
}

int find_set(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find_set(parent[x]);
}

int  union_set(int a, int b)
{
    int repa = find_set(a);
    int repb = find_set(b);
    if (repa == repb)
        return 0;
    if (size_[repa] > size_[repa])
    {
        parent[repb] = repa;
        size_[repa] += size_[repb];
    }
    else
    {
        parent[repa] = repb ;
        size_[repb] += size_[repa];
    } 
    return 1 ;
}

int main()
{
    int n, m;
    cin >> n >> m;
    make_set(n);
    vector< pair< int  ,int > > edges;
    vector< int >  degree( n+1  , 0 );
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back( {x, y });
        degree[x] ++;
        degree[y] ++;
    };
    int count  =0 ;
    for( auto i : edges){
        if(degree[i.first] == 2  && degree[i.second]==2 && !union_set( i.first ,i.second )){
            count++;
        }
    }
    cout<<count<<endl;



    return 0;
}