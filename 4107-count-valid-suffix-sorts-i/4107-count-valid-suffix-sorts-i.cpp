class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();

        vector<int> nums_c(nums), target_c(target);
        sort(nums_c.begin(), nums_c.end());
        sort(target_c.begin(), target_c.end());

        if(nums_c != target_c) return 0;

        bool t_sorted[100'000] = { false, };
        t_sorted[n - 1] = true;
        
        for(int i = n - 2; i >= 0; i--){
            if(target[i] >= target[i + 1]) t_sorted[i] = true;
            else break;
        }

        int res = 0;

        for(int i = 0; i < n; i++){
            if(t_sorted[i]) res++;

            if(nums[i] != target[i]) break;
        }

        return res;
    }
};