#include <vector>
#include <unordered_map>
#include <utility>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int > & A,vector<int >&  B, int N)
{
    unordered_map<int, vector<pair<int, int>>> adj;
    for (int i = 0; i < N; ++i)
    {
        adj[A[i]].emplace_back(B[i], 1);
        adj[B[i]].emplace_back(A[i], 0);
    }

    int reorient = 0;
    vector<bool> visited(N + 1, false);
    stack<pair<int, int>> s;
    s.emplace(0, -1);
    visited[0] = true;

    while (!s.empty())
    {
        pair<int, int> current = s.top();
        s.pop();
        int city = current.first;
        for (auto &edge : adj[city])
        {
            int neighbor = edge.first;
            int direction = edge.second;
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                if (direction == 1)
                {
                    reorient++;
                }
                s.emplace(neighbor, city);
            }
        }
    }

    return reorient;
}
int main (){
     vector<int > a  = { 0 ,1,1 ,1 ,1};
     vector<int >  b = { 1 ,2,3,4,5};
     int  n  = 5;
     cout<<solution( a , b, n) ;
    return 0 ;
}