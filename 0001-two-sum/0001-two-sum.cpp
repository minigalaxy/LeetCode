class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res = { 0, 0 };

        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(1LL * nums[i] + nums[j] == target){
                    res[0] = i;
                    res[1] = j;
                }
            }
        }

        return res;
    }
};