#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main() {
    int N, K, M;
    cin >> N >> K >> M;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    // Dynamic programming table: dp[k][r] = max sum modulo M that can be formed with k elements
    vector<vector<int>> dp(K + 1, vector<int>(M, -1));
    dp[0][0] = 0; // We can form sum 0 using 0 elements
    for (int i = 0; i < N; ++i) {
        for (int k = K - 1; k >= 0; --k) {
            for (int r = 0; r < M; ++r) {
                if (dp[k][r] != -1) {
                    int new_sum = dp[k][r] + A[i];
                    int new_r = new_sum % M;
                    dp[k + 1][new_r] = new_sum;
                }
            }
        }
    }
    int max_multiple_of_M = dp[K][0];
    cout << max_multiple_of_M << endl;
    return 0;
}
