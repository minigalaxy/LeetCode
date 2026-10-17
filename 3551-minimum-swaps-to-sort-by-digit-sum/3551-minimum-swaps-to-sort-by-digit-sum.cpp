class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n_size = nums.size();

        pair<pair<int, int>, int> nums_2[100'000];

        for(int i = 0; i < n_size; i++){
            int n_sum = 0;

            for(char c: to_string(nums[i])) n_sum += c - '0';

            nums_2[i] = { { n_sum, nums[i] }, i };
        }

        sort(nums_2, nums_2 + n_size);

        int res = 0;

        for(int i = 0; i < n_size; i++){
            if(nums[i]){
                int cur = i;

                while(nums[cur]){
                    nums[cur] = 0;
                    res++;

                    cur = nums_2[cur].second;
                }

                res--;
            }
        }

        return res;
    }
};