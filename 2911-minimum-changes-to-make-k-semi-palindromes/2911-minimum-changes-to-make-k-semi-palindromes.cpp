class Solution {
    int n, k;
    string s;
    int min_change[200][200];
    int dp[201][200];

    void init(){
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= k; j++){
                dp[i][j] = 200;
            }
        }

        dp[n][0] = 0;

        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                int l = j - i + 1;

                min_change[i][j] = 200;

                for(int d = 1; d <= l / 2; d++){
                    if(l % d == 0){
                        int diff = 0;

                        for(int a = 0; a < d; a++)
                            for(int m = 0; m < (l / d) / 2; m++)
                                if(s[i + a + d * m] != s[i + a + d * (l / d - m - 1)]) diff++;
                        
                        min_change[i][j] = min(min_change[i][j], diff);
                    }
                }
            }
        }
    }

public:
    int minimumChanges(string s, int k) {
        n = s.size();
        this->s = s;
        this->k = k;

        init();

        for(int i = n - 1; i >= 0; i--)
            for(int j = 1; j <= k; j++)
                for(int x = i + 1; x < n; x++)
                    dp[i][j] = min(dp[i][j], dp[x + 1][j - 1] + min_change[i][x]);

        return dp[0][k];
    }
};