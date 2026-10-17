class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<pair<pair<int, int>, int>> nums_2;

        for(int i = 0; i < nums.size(); i++){
            int n_sum = 0;

            for(char c: to_string(nums[i])) n_sum += c - '0';

            nums_2.push_back({ { n_sum, nums[i] }, i });
        }

        sort(nums_2.begin(), nums_2.end());

        int res = 0;

        for(int i = 0; i < nums.size(); i++){
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