#include <bits/stdc++.h>
using namespace std;
#define int long long 

class SegmentTree{
    public  :
    vector<int > t , islazy , unpropvalue;

    SegmentTree(int len ){
        t.resize( 4*len , 0);
        islazy.resize( 4*len , 0);
        unpropvalue.resize( 4*len , 0);
    }
     void apply ( int ind  , int tl ,int tr , int val){
        if( tl != tr){
            islazy[ind] =1;
            unpropvalue[ind] += val;
        }
        t[ind] = t[ind ] + ( tr-tl +1)*val;
     }
    void push_down ( int ind , int tl , int tr){
         if( !islazy[ind])return ;
         islazy[ind] = 0 ;
         int tm = ( tl+ tr)/2;
         apply ( 2*ind ,tl , tm , unpropvalue[ind]);
         apply ( 2*ind +1  , tm+1  , tr, unpropvalue[ind]);
         unpropvalue[ind] = 0 ;
    }
    int query ( int ind , int tl , int tr , int l , int r){
        if( tl > r ||  l > tr)return  0 ;
        if( l<= tl && tr <=  r)return t[ind];

        push_down ( ind , tl , tr);
        int tm = ( tl + tr)/2 ;
        int leftans  = query ( 2*ind , tl , tm, l , r);
        int rightans = query ( 2*ind  +1  , tm+1 , tr ,l , r);
        return leftans+ rightans;
    }
    void update ( int ind  , int tl , int tr , int l , int r, int v){
        if(  l>tr  || tl >r)return ;
        if( l<= tl && tr <= r) {
             apply ( ind , tl , tr , v);
             return ;
        }
        push_down ( ind , tl  , tr);
        int tm = ( tl + tr)/2 ;
        update( 2*ind , tl , tm , l , r, v);
        update( 2*ind+1  , tm+1 , tr, l , r, v);
        t[ind] = t[2*ind] + t[2*ind+1];
    }
};
int32_t main()
{
    int n, m;
    cin >> n >> m;
    SegmentTree seg( n);
    while (m--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            seg.update( 1 , 0 , n-1, l , r-1 , v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout<<seg.query( 1 ,0 , n-1 , l ,r-1)<<endl;;
        }
    }
    return 0;
}