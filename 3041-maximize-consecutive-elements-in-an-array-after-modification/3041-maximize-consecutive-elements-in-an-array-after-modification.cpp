class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int res = 1;

        int dp[2][2] = { { 1, 1 },  };

        for(int i = 1; i < nums.size(); i++){
            dp[i & 1][0] = 1;
            dp[i & 1][1] = 1;

            if(nums[i] - nums[i - 1] == 2){
                dp[i & 1][0] = dp[(i - 1) & 1][1] + 1;
            } else if(nums[i] - nums[i - 1] == 1){
                dp[i & 1][0] = dp[(i - 1) & 1][0] + 1;
                dp[i & 1][1] = dp[(i - 1) & 1][1] + 1;
            } else if(nums[i] - nums[i - 1] == 0){
                dp[i & 1][0] = dp[(i - 1) & 1][0];
                dp[i & 1][1] = max(dp[(i - 1) & 1][1], dp[(i - 1) & 1][0] + 1);
            }

            res = max(res, max(dp[i & 1][0], dp[i & 1][1]));
        }

        return res;
    }
};