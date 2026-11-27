class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<pair<int, int>> free;
        
        for(int i = 0; i < n; ++i){
            int cnt = 0;

            for(int j = 0; j < n; ++j)
                if(items[j][0] % items[i][0] == 0) cnt++;

            free.push_back({ cnt, items[i][1] });
        }

        int min_cost = 1'500;

        for(int i = 0; i < n; ++i) min_cost = min(min_cost, items[i][1]);

        int dp[1'001][1'501] = { 0, };

        for(int i = 0; i < n; ++i)
            for(int j = 0; j <= budget; ++j){
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

                if(j >= free[i].second)
                    dp[i + 1][j - free[i].second] = max(dp[i + 1][j - free[i].second], dp[i][j] + free[i].first);
            }

        int res = 0;

        for(int i = 1; i <= n; ++i)
            for(int j = 0; j <= budget; ++j)
                res = max(res, dp[i][j] + (j / min_cost));

        return res;
    }
};