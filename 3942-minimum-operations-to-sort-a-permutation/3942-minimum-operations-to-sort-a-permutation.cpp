class Solution {
public:
    int minOperations(vector<int>& nums) {
        int N = nums.size();
        int asc = 0, desc = 0, asc_idx = 0, desc_idx = 0;
        
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] < nums[i + 1]) asc++, asc_idx = i;
            else desc++, desc_idx = i;
        }

        if(nums.back() < nums.front()) asc++, asc_idx = N - 1;
        else desc++, desc_idx = N - 1;

        if(N == 2) return nums.front() > nums.back();
        else if(asc == 1) return ((asc_idx == N - 1) ? 1 : min(asc_idx + 2, N - 1 - asc_idx + 1));
        else if(desc == 1) return ((desc_idx == N - 1) ? 0 : min(desc_idx + 1, N - 1 - desc_idx + 2));
        else return -1;
    }
};