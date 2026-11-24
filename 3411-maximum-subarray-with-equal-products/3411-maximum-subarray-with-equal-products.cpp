class Solution {
public:
    int maxLength(vector<int>& nums) {
        int res = 1;

        for(int i = 0; i < nums.size(); i++){
            int prod_arr = 1, gcd_arr = nums[i], lcm_arr = nums[i];

            for(int j = i; j < nums.size(); j++){
                prod_arr *= nums[j];
                gcd_arr = gcd(gcd_arr, nums[j]);
                lcm_arr = lcm(lcm_arr, nums[j]);

                if(prod_arr > gcd_arr * lcm_arr) break;

                res = max(res, j - i + 1);
            }
        }

        return res;
    }
};