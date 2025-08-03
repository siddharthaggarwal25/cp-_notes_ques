#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minEnergy(int A) {
        if (A <= 1) {
            return 0;
        }

        const int INF = 1e9;
        std::vector<int> dp(A + 1, INF);

        dp[1] = 0;

        for (int i = 1; i <= A; ++i) {
            if (dp[i] == INF) {
                continue;
            }

            if (2 * i <= A) {
                dp[2 * i] = std::min(dp[2 * i], dp[i] + 2);
            }
            
            for (int k = 1; k <= i; ++k) {
                if (i + k <= A) {
                    dp[i + k] = std::min(dp[i + k], dp[i] + k + 1);
                } else {
                    break;
                }
            }
        }
        
        return dp[A];
    }
};

int main() {
    Solution s;
    
    int A1 = 19;
    std::cout << "Minimum energy for A = " << A1 << " is: " << s.minEnergy(A1) << std::endl;

    int A2 = 10;
    std::cout << "Minimum energy for A = " << A2 << " is: " << s.minEnergy(A2) << std::endl;

    return 0;
}