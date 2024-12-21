#include <iostream>
#include <vector>
using namespace std;

const int MOD = 10007;

long long modInverse(long long a) {
// Function to calculate modular inverse using Fermat's Little Theorem
    long long result = 1, p = MOD - 2; // Since MOD is prime
    while (p) {
        if (p & 1) result = (result * a) % MOD;
        a = (a * a) % MOD;
        p >>= 1;
    }
    return result;
}
// Function to calculate binomial coefficient C(n, k)
long long binomialCoeff(int n, int k) {
    if (k > n) return 0;
    long long res = 1;
    if (k > n - k) k = n - k;
    for (int i = 0; i < k; ++i) {
        res = (res * (n - i)) % MOD;
        res = (res * modInverse(i + 1)) % MOD;
    }
    return res;
}


// Function to calculate Catalan number modulo MOD
long long catalanNumber(int n) {
    if (n <= 1) return 1;
    long long catalan = binomialCoeff(2 * n, n);
    catalan = (catalan * modInverse(n + 1)) % MOD;
    return catalan;
}

// Function to count valid subdivisions based on non-intersecting diagonals
long long countValidSubdivisions(int n) {
    if (n < 3) return 1;  // Base case for polygons with fewer than 3 sides

    vector<long long> dp(n + 1, 0);
    dp[0] = 1; // C_0 = 1
    dp[1] = 1; // C_1 = 1

    // Fill the dynamic programming table
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] = (dp[i] + dp[j] * dp[i - 1 - j]) % MOD;
        }
    }

    return dp[n];
}

// Function to calculate total number of possibilities
long long totalPossibilities(int n) {
    if (n < 3) return 1; // A polygon with fewer than 3 sides has no diagonals

    long long catalan = catalanNumber(n - 2); // Calculate the Catalan number for n-2
    long long validSubdivisions = countValidSubdivisions(n); // Count valid subdivisions

    // Final result: total possibilities
    long long result = (catalan + validSubdivisions) % MOD;
    result = (result + 3) % MOD; // Add 3 as specified

    return result;
}

int main() {
    // Testing for n = 24 and n = 47
    int n1 = 24;
    int n2 = 47;

    cout << "The total number of possibilities for a polygon with " << n1 << " sides: " << totalPossibilities(n1) << endl;
    cout << "The total number of possibilities for a polygon with " << n2 << " sides: " << totalPossibilities(n2) << endl;

    return 0;
}
