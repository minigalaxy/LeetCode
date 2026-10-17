class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<long long, int> s;
        vector<int> res;

        for(int i = 0; i < nums.size(); i++){
            if(s[1LL * target - nums[i]] > 0){
                res = { s[1LL * target - nums[i]] - 1, i };
            } 
            else s[nums[i]] = i + 1;
        }

        return res;
    }
};