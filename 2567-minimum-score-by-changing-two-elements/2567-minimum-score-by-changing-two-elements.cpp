const int MAX = 1'000'000'000;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int h[3] = { 0, 0, 0 }, l[3] = { MAX, MAX, MAX };
        h[0] = l[0] = nums[0];

        if(nums.size() > 10)
            for(int i = 1; i < nums.size(); i++){
                for(int j = 0; j < 3; j++)
                    if(nums[i] >= h[j]){
                        for(int k = 2; k > j; k--) h[k] = h[k - 1];
                        h[j] = nums[i];
                        break;
                    }
                for(int j = 0; j < 3; j++)
                    if(nums[i] <= l[j]){
                        for(int k = 2; k > j; k--) l[k] = l[k - 1];
                        l[j] = nums[i];
                        break;
                    }
            }
        else {
            sort(nums.begin(), nums.end());

            for(int i = 0; i < 3; i++){
                l[i] = nums[i];
                h[i] = nums[nums.size() - 1 - i];
            }
        }

        return min(h[1] - l[1], min(h[2] - l[0], h[0] - l[2]));
    }
};