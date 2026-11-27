class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        int min_cost = 1'500;

        for(int i = 0; i < n; ++i) min_cost = min(min_cost, items[i][1]);

        vector<pair<int, int>> free;
        
        for(int i = 0; i < n; ++i){
            int cnt = 0;

            for(int j = 0; j < n; ++j)
                if(items[j][0] % items[i][0] == 0) cnt++;

            if(items[i][1] < min_cost * cnt) free.push_back({ cnt, items[i][1] });
        }

        int dp[1'001][1'501] = { 0, };

        for(int i = 1; i <= free.size(); ++i)
            for(int j = 0; j <= budget; ++j)
                dp[i][j] = max(dp[i - 1][j], (j + free[i - 1].second <= budget) ? dp[i - 1][j + free[i - 1].second] + free[i - 1].first : 0);

        int res = 0;

        for(int i = 0; i <= budget; ++i)
            res = max(res, dp[free.size()][i] + (i / min_cost));

        return res;
    }
};