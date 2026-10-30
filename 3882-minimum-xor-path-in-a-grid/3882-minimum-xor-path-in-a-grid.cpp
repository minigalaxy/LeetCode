class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        bool dp[2][1'000][1'024] = { false, };

        dp[0][0][grid[0][0]] = true;

        for(int i = 0; i < m - 1; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < 1'024; k++){
                    if(dp[0][j][k]){
                        dp[1][j][k ^ grid[i + 1][j]] = true;
                        if(j + 1 < n) dp[0][j + 1][k ^ grid[i][j + 1]] = true;
                    }
                }
            }

            for(int j = 0; j < n; j++){
                for(int k = 0; k < 1'024; k++){
                    dp[0][j][k] = dp[1][j][k];
                    dp[1][j][k] = false;
                }
            }
        }

        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < 1'024; j++){
                if(dp[0][i][j]) dp[0][i + 1][j ^ grid[m - 1][i + 1]] = true;
            }
        }

        for(int i = 0; i < 1'024; i++){
            if(dp[0][n - 1][i]) return i;
        }

        return -1;
    }
};