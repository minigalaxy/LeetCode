class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int prefix_sum[101] = { 0, };

        for(int i = 0; i < nums.size(); i++) prefix_sum[i + 1] = prefix_sum[i] + nums[i];

        int res = 100'001;

        for(int i = l; i <= r; i++){
            for(int j = 0; j + i - 1 < nums.size(); j++){
                int sum = prefix_sum[j + i] - prefix_sum[j];

                if(sum > 0) res = min(res, sum);
            }
        }

        if(res == 100'001) res = -1;

        return res;
    }
};