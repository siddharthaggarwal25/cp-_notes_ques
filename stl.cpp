// STL Library

//   1>>vectors;
//   vectors are array of dynamic size
//   vector<data-type> vec(size//not necessary);
//    can be access using indexing(0 to n) or ausing auto keyword (identifies the data-type by itself)
//   .push_back(value)// to add value at the end;
//   .resize()//to resize to diffrent size;
//   .sort(vec.begin(),vec.end())// to sort the array in inc order // vec.end()givcves the iterator at the last +1 index of the vector , ie it uses the address and one index less
//   .reverse(vec.begin ,vec.end());
//   .pop_back();

//->>>>> swap(a,b)        variabels names a and b;

// 2>>structure
//  use to store elements of diffrent data types together ,it is a user defined data type
/*  struct name{
    string sfirztrname;
    string last name ;
}  .......... we can also declare array of this data type
*/

// 3>>PAIR
//  pair<data-type1 , data-type2> name;
// excess>>> name.first, name.second;
// used mostly with vectors ;

//   4>>SET
// set is a special kind of stl container which stores unique elemnys in sorted order
//  set<data-type> setName;
// set.insert(value);
// set.size();
// set.erase(value);
/*  for(auto it = st.begin() , it!= st.end() ,st++){
    cout<<*it<<endl;  .......for printing all elements;
}
*/

// 5>>MAP
// map is a special kind of stl container which stores elemnts a key-value pair .no two mappec values
// can have the same key . all the key are stored in ascending order
// map<data-type1 , data-type2> name;
// name.size();
// name.erase(key);

//>>>>>>>>>>>>>> THESE ARE SOME IMPORTANT STL CONTINERS  <<<<<<<<<<<<<<<<<<<<<<<

// TOPICS COVERED;
//  1.Pattern printing problems (Sourabh Shukla Videos on Youtube)
//  2.time complexity analysis
//  3.linear search and circular array representation (any article, no need to practice)
//  4.palindrome and other numbers(perfect, Armstrong) for basic number problems
//  5.Simple Hashing Problem(frequency counting and stuffs)
//  6.Prefix Sum Problems(1D and 2D) {CP Sheet has problems}
//  7.Sliding window technique(CP Sheet has problems)

// BInary search (ongoing )
// takes log(n) time for serc  ing a value in worst case and  used in sorted array (monotonic function );
/*
{
    int l=0 ; hi = n-1;
    int mid ;
    int pos=-1;
    while(lo<=hi){
        mid= low + (high -low)/2;  ........to dont overfloww always use this
        if(arr[mid]== x){
            pos=mid ;
            break;
        }
        else if(arr[mid]<x)    {
        lo = mid +1 }
        else {
        hi = mid - 1;
       }
    })
}
*/

// GCD FOR 2 NUMBER (EUCLIEDEAN ALOGORITHM)

/*
->see time complexity and acoordingly find your solution
->view the problem from front as well as back
->prefer loops over if-else
->search for hints like small values for brute force
->A,B question are hardly 20 lines of code
->if you do i-1 clamp it to zero
->check for edge cases like 0-1 or for binary string all 0's or 1's mindfully
->check for ll overflow
->check control flow make sure you return on a priority basis
->dont get stuck in a question for a long time go to next question and then return
*/

// PRIME NUMBER (sieve)
/*
prime number can be calculated in sqrt(n) time complexicity rather than in n ;
as the number have two factor a*b ; if we calcuated using sqrt n and a factor is found than
another one willl be n/factor1

using sieve of erathormes

bool isPrime[1e6+1]
if isprime[i] = 1 //is a prime nuber
if isprime[i] = 0 //is not a prime number

for(int i=0  ;i<= 1000000 ;i++){]
isprime[i]=1;
}

isprime[0]=isprime[1]=0;
for(int i=2 ;i*i <=1000000 ;i++){
    if(isPrime[i] ==1){
        for(int  j  = i*i ; j< 100000 ; j=j+i ){
        isprime[i]=0;
        }
    }
}

smallest prime factor

int spf[1000001];
for(int i=0 ;i< 1000000 ;i++){
    cpf[i] = i;
}
for(int i=2  ;i*i<=1e6  ;i++){
    if(spf[i] ==i){
        for(int j= i*i ;j<=1e6 ;j=j+i){
            spf[j]=i;
        }
    }
}


*/

// binary exponentiation

int binaryExponentiation(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }

    int res = binaryExponentiation(x, n / 2);

    if (n % 2 == 0)
        return res * res;
    return res * res * x;
}
// gcd

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// seive

int arr[1e6 + 1];
for (int i = 0; i <= 1e6; i++)
{
    arr[i] = 1
}
arr[0] = arr[1] = 0; // no ta prime numbe r

fir(int i = 2; i * i <= 1e6; i++)
{
    if (arr[i])
    {
        for (unt j = i * i; j < 1e6; j = j + i)
        {
            arr[j] = 0;
        }
    }
}

//  euler toitent funcion

phi(i)->>> count the number of coprime nunber from 1 to n that are coprime with n;
for
    prime numbr phi(i) = i - 1;

#include <bits/stdc++.h>
using namespace std;
#define int long
int k;
int eps = 1e-7;
int check_length(int x, int arr[], int n)
{
    int pieces = 0;
    for (int j = 0; j < n; j++)
    {
        pieces += (int)(arr[j] / x);
    }
    return pieces;
}
int main()
{
    int n;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int minimum = arr[0];
    int low = 0, high = minimum, mid;
    int ans;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (check_length(mid, arr, n) > k)
        {
            low = mid + eps;
        }
        else if (check_length(mid, arr, n) < k)
        {
            high = mid - eps;
        }
        else
        {
            ans = mid;
            low = mid + eps;
        }
    }
    cout << ans;
}

// DFS
vector<vector<int>> adjacentList(n);
vector<int> vis(n, 0);
void dfs(int node)
{

    vis[node] = 1;

    for (auto child : adjacentList[node])
    {
        if (!vis[child])
        {

            dfs(child);
        }
    }
}

// DFS using colors

vector<vector<int>> adjacnctList(n);
vector<int> color(n);
// if  v[] =0  ->> unvisted    white
// if  v[] =1 ->> visted but not complted    grey
// if  v[] =2  ->> completed visited  black

void dfs(int node)
{
    color[node] = 1;

    for (auto child : adjacentList[node])
    {
        if (color[child] == 0)
        {
            dfs(child);
        }
    }

    color[node] = 2;
}
//
// DFS using parent  , used in case  of trees only

vector<vector<int>> v(n);
void dfs(int node, int parent)
{
    // operation to be perfored before enetering a node
    for (auto child : adjacentList[node])
    {
        // operation  to be performend before going to child node ...  doing down
        if (child == parent)
        {
            continue;
        }
        dfs(child);

        // operation to be performend after visiting child nodes  - ..  going upward
    }
    // operation to be performend after competing the  node
}

//  to find  cylce in undirected graph using dfs ,  we can  use parent and the current code and color coding  ,
//  when we visit a child check that   is its child is not is parent and its color is grey  ie 1  then the loop existe and return true ;

// in case of bfs for findind cylce we can inizalized all dis with infiite and then then traverse a  node if its dis is less than the current  dis  then   cylce exist in bfs

// remeber to cal  bfs for every node as there can be a case where each mpde may not be joindec=d together

// finding cycle in  directed graph

vector<int> color(n, 0);

bool dfs(int node)
{
    color[node] = 1;

    for (auto cjhild : adjacentlist[node])
    {
        if (color[child] == 1)
        {
            return true;
        }
        else if (color[child] == 0)
        {
            bool found = dfs(child);
            if (found)
            {
                return true;
            }
        }
    }
    color[node] = black;
    return false;
}

//   calculating gs=cd for eact subtree in a given tree

vector<vector<int>> v(n);
vector<int> value(n);
vector<int> ans(n);
void dfs(int node, int parent)

{

    ans[node] = value[node];
    for (auto child : v[node])
    {
        if (child == parent)
        {
            continue;
        }
        dfs(child);
        answer[node] = gcd(answer[node], answer[child]);
    }
}

// for checking is the giben graph is bi[pratite or not ]

bool bipartite(int node, int parent, vector<vector<int>> &adj, vector<int> &color)
{

    for (auto child : adj[node])

    {
        if (child == parent)
        {
            continue;
        }
        if (color[child] != -1)
        {
            color[child] = color[node];
            return false;
        }
        else
        {
            color[child] = color[node] ^ 1;
            bool valid = bipartite(child, adj, color);
            if (!valid)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<int> color(n, -1);
    vector<vector<int>> adj(n);

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 0;
            ans &= barpaptite(i, -1, adj, color)
        }
    }
    if (ans)
    {
        cout << "yes" << endl;
    }
}

// topological sort  using dfs   there is another method also
vector<vector<int>> adj(n);
vector<int> vis(n);
stack<int> s;
void dfs(int node)
{
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
    s.push(node);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {

        int u, v;
        cin >> u >> v;
        afj[u].push_back(v);
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    reutrn 0;
}

// dijistra algorithm

vector<int> dis(n, 1e9);  // this is the distanv=ce array intilaized with alarge value 
vector<vector<pair<int, int>>> adj_weight(n); // this is aj list with  vertex between the edge and the weight
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // priority  que  with first element dfistnace and second elemnet is node  in smallest element on top priority
// ,we can use a parent vector for stroning the path 
vector<int >  parent ( n , 0 ); 
pq.push({0, 0});
dis[0] = 0;
while (!pq.empty())
{
    int distance = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if (distance >= dis[node])
    {
        continue;
    }
    for (auto child : adj[node])
    {
        int adjWeight = child.second;
        int adjNode = child.first;
        if (distance + adjWeight < dis[adjNode])
        {
            dis[adjNode] = distance + adjWeight;
            pq.push({dis[adjNode], adjNode});
            parent [ adjNode] = node;
        }
    }

    // printing tht path ;
    while( n!= 0  ){ // 0 is hthe soure 
        cout<< par[n];
        n = par[n ]; 
    }
}


// 

// good  fact is thaht set<par<int , int > s , is same as set<array<int , 2 > > s;


// Bellman ford algorithm , it is used to find the single souce sortst path , it help in checking that is their a negative4 cycle 
vector<int > dis( n , 1e9);
vector< pair < pair <int , int > , int   >  edges ( n );

for( int i=0 ;i< n-1  ; i++){
    for( auto child :  edges)
    { int u  = child.first.first;
     int v = child.first.second ;
     int w = child.second ;
     dis[ v] = min (  dis[u] + w , dis[ v]);  }   
}
int flag  =0  ;
for( auto e : edges){
    int u  = child.first.first;
     int v = child.first.second ;
     int w = child.second ;
    if (dist[u] + w < dist[v])
        flag = 1;

}
 // flag 1 means negatiove cycle 


  /// Ford Warshell algorithm 

  // use adjacecy matrix rather than adjacentcy list 

  vector< vector<int > > adj(n , vector<int> ( n , inf));
  for(int i=0 ;i< n ;i++){
    adj[i][i] = 0;
  } 
  // add edges dstance '

  for( int k=0 ;k< n ; k++){
    for( int i=0 ;i< n ;i++){
        for( int  j=0 ;j< n ;j++){
            dis[i][j] = min ( dis[i][j]  , dis[i][k] + dis[k][j]);
        }
    }
  }

// disjoint set unoion 

int parent[100001]
int size[100001]
 void make_set(){
    for( int i=0 ;i< n ;i++){
        size[i]= 1;
        parent [i] = i;
    }
 }
 int  find_set(int x){
    if( parent[x] == x) return x ;
    return parent[x]= find_set( parent[x]);
 }

void union_set(int a , int b ){
    int finda = find_set(a);
    int findb  = find_set(b);
    if (finda == findb) return 

    if( size[finda] < size[findb]){
        swap( finda , findb )
    }
    parent[findb]= parent[finda]
    size[finda] += size[findb]


}