const int MOD = 1'000'000'000 + 7;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int path[500][500][2] = { 1, };

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i + 1 < m){
                    if(grid[i][j] == 1) path[i + 1][j][0] = (path[i + 1][j][0] + path[i][j][1]) % MOD;
                    else path[i + 1][j][0] = ((path[i + 1][j][0] + path[i][j][0]) % MOD + path[i][j][1]) % MOD;
                }
                if(j + 1 < n){
                    if(grid[i][j] == 1) path[i][j + 1][1] = (path[i][j + 1][1] + path[i][j][0]) % MOD;
                    else path[i][j + 1][1] = ((path[i][j + 1][1] + path[i][j][0]) % MOD + path[i][j][1]) % MOD;
                }
            }
        }

        return (path[m - 1][n - 1][0] + path[m - 1][n - 1][1]) % MOD;
    }
};