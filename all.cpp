#Biconnected componennts 
// biconnected componenmts
// finding bridge in graph 
class Solution {
public:
    int timer =1 ;
    void dfs( int node , int par , vector< int > &vis , vector< int > & low  , vector< int >& time  , vector<vector< int >> &adj  , vector<vector<int >>&bridges){
        vis[node]=1;
        time[node]=timer;
        low[node]= timer;
        timer++;

        for( auto child  : adj[node]){
            if( child  == par)continue ;
            if( vis[child] == 0){
                dfs( child , node , vis , low , time , adj , bridges);
                low[ node ] = min ( low[node] , low[child]);
                if( low[child] > time[node]){
                    bridges.push_back( { child , node});
                }

            }else{
                low[ node ] = min ( low[node] , low[child]);
            }
        }
    } 
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> bridges;
        vector<vector<int>> adj(n);
        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0), low(n), time(n);
        dfs(  0  ,0 ,vis , low , time , adj , bridges );
        return bridges;
    }
};