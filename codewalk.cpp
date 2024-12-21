#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int INF = INT_MAX; 
// apllying chinese postamn therom 
void floydWarshall(vector<vector<int>>& dist, int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int minMatchingDP(const vector<int>& oddVertices, const vector<vector<int>>& dist) {
    int n = oddVertices.size();
    vector<int> dp(1 << n, INF);  
    dp[0] = 0; 

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) { 
                for (int j = i + 1; j < n; j++) {
                    if (!(mask & (1 << j))) { 
                        int newMask = mask | (1 << i) | (1 << j);
                        dp[newMask] = min(dp[newMask], dp[mask] + dist[oddVertices[i]][oddVertices[j]]);
                    }
                }
                break; 
            }
        }
    }
    
    return dp[(1 << n) - 1];
}

int chinesePostman(vector<vector<int>>& graph, int V) {
    vector<int> degree(V, 0);
    int totalWeight = 0;

    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != INF) {
                totalWeight += graph[u][v];
                degree[u]++;
            }
        }
    }

    totalWeight /= 2; 

    vector<int> oddVertices;
    for (int i = 0; i < V; i++) {
        if (degree[i] % 2 == 1) {
            oddVertices.push_back(i);
        }
    }

    if (oddVertices.empty()) {
        return totalWeight;
    }

    vector<vector<int>> dist = graph;
    floydWarshall(dist, V);

    int minCost = minMatchingDP(oddVertices, dist);

    return totalWeight + minCost;
}

int32_t main() {
    int k;
    cin >> k;

    int c0 = k;
    int n = (c0 % 17) + 3;  
    vector<int> weight(n);

    for (int i = 0; i < n; i++) {
        weight[i] = ceil((n + 1) / static_cast<double>((i + 1) + 1));
    }

    vector<vector<int>> graph(n, vector<int>(n, INF));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                graph[i][j] = weight[i] + weight[j];
            } else {
                graph[i][j] = INF; 
            }
        }
    }

    graph[0][n - 1] = INF;
    graph[n - 1][0] = INF;

    // cout << "Graph adjacency matrix:" << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (graph[i][j] == INF) cout << "INF ";
    //         else cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int c1 = chinesePostman(graph, n);
    int  c2 =  ( c1% 107) + 3 ;

 
    return 0;
}
