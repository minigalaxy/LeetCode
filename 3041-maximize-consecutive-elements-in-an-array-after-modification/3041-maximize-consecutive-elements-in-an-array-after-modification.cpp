class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int cnt[1'000'000] = { 0, };
        int mx = *max_element(nums.begin(), nums.end()) - 1;
        int mn = *min_element(nums.begin(), nums.end()) - 1;
        
        for(int i = 0; i < nums.size(); i++) cnt[nums[i] - 1]++;
        for(int i = mn + 1; i <= mx; i++) cnt[i] += cnt[i - 1];

        int nums2[100'000];
        
        for(int i = nums.size() - 1; i >= 0; i--) nums2[--cnt[nums[i] - 1]] = nums[i] - 1;

        int res = 1;

        int dp[2] = { 1, 1 };

        for(int i = 1; i < nums.size(); i++){
            int d = nums2[i] - nums2[i - 1];

            if(d == 2){
                dp[0] = dp[1] + 1;
                dp[1] = 1;
            } else if(d == 1){
                dp[0]++;
                dp[1]++;
            } else if(d == 0){
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