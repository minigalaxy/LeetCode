class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        int res = 0;

        for(int k = 1; k <= n; k++){
            if(n % k == 0){
                bool flag = true;

                for(int i = 0, prev_max = 0; flag && i < n; i += k){
                    int cur_max = 0;

                    int dec = 0;

                    for(int j = 0, prev = 0; flag && j < k; j++){
                        cur_max = max(cur_max, nums[i + j]);

                        if(nums[i + j] < prev_max) flag = false;
                        if(nums[i + j] < prev) dec++;

                        prev = nums[i + j];
                    }

                    if(nums[i] < nums[i + k - 1]) dec++;

                    if(dec > 1) flag = false;

                    prev_max = cur_max;
                }

                if(flag) res += k;
            }
        }

        return res;
    }
};