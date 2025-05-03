class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1), gap(n + 1);
        dp[0] = 1;
        if (n >= 1) dp[1] = 1;
        if (n >= 2) dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            gap[i - 1] = (gap[i - 2] + dp[i - 3]) % MOD;
            dp[i] = (dp[i - 1] + dp[i - 2] + 2 * gap[i - 1]) % MOD;
        }

        return dp[n];
    }
};
