class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int res = 1;

        int dp[2] = { 1, 1 };

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - nums[i - 1] == 2){
                dp[0] = dp[1] + 1;
                dp[1] = 1;
            } else if(nums[i] - nums[i - 1] == 1){
                dp[0]++;
                dp[1]++;
            } else if(nums[i] - nums[i - 1] == 0){
                dp[0] = dp[0];
                dp[1] = max(dp[1], dp[0] + 1);
            } else {
                dp[0] = 1;
                dp[1] = 1;
            }

            res = max(res, max(dp[0], dp[1]));
        }

        return res;
    }
};