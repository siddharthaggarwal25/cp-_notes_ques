#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

// Function and parameter names restored as requested
int findMaxLength(vector<int> skills, int k) {
    int n = skills.size();
    if (n == 0) {
        return 0;
    }

    int max_v = 2001; 

    vector<vector<int>> dp(k + 1, vector<int>(max_v, 0));
    vector<pair<int, int>> b1(k + 1, {0, -1});
    vector<pair<int, int>> b2(k + 1, {0, -1});

    int ans = 0;

    for (int val : skills) {
        
        vector<int> curr_lens(k + 1);

        for (int j = 0; j <= k; j++) {
            
            int l_same = 1 + dp[j][val];
            int l_diff = 0;

            if (j > 0) {
                if (b1[j - 1].second != val) {
                    l_diff = 1 + b1[j - 1].first;
                } else {
                    l_diff = 1 + b2[j - 1].first;
                }
            }
            
            curr_lens[j] = max(l_same, l_diff);
            ans = max(ans, curr_lens[j]);
        }

        for (int j = 0; j <= k; j++) {
            int n_len = curr_lens[j];
            
            dp[j][val] = n_len;

            if (n_len > b1[j].first) {
                if (b1[j].second != val) {
                    b2[j] = b1[j];
                }
                b1[j] = {n_len, val};
            } else if (n_len > b2[j].first && val != b1[j].second) {
                b2[j] = {n_len, val};
            }
        }
    }

    return ans;
}

int main() {
    vector<int> skills0 = {1, 1, 2, 3};
    int k0 = 1;
    cout << "Sample Case 0 Output: " << findMaxLength(skills0, k0) << endl; 

    vector<int> skills1 = {1, 1, 2, 1, 2, 2, 1, 2};
    int k1 = 2;
    cout << "Sample Case 1 Output: " << findMaxLength(skills1, k1) << endl; 

    return 0;
}