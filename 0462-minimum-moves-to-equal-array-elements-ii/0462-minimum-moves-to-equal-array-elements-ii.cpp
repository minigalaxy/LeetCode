class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        long long sum[100'001] = { 0, };

        for(int i = 0; i < n; i++) sum[i + 1] = sum[i] + nums[i];

        long long res = 100'000'000'000'000LL;

        for(int i = 0; i < n; i++){
            res = min(res, 1LL * nums[i] * i - sum[i] + sum[n] - sum[i + 1] - 1LL * nums[i] * (n - 1 - i));
        }

        return res;
    }
};