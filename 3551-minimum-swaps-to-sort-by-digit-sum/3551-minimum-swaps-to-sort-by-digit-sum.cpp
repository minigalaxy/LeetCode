class Solution {
public:
    struct Num
    {
        int n, sum, idx;
    };

    int minSwaps(vector<int>& nums) {
        int n_size = nums.size();

        Num nums_2[100'000];

        for(int i = 0; i < n_size; i++){
            int n_sum = 0;

            for(int t = nums[i]; t > 0; t /= 10) n_sum += t % 10;

            nums_2[i] = { nums[i], n_sum, i };
        }

        sort(nums_2, nums_2 + n_size, [&](Num &a, Num &b){
            if(a.sum == b.sum) return a.n < b.n;
            else return a.sum < b.sum;
        });

        int res = 0;

        for(int i = 0; i < n_size; i++){
            if(nums[i]){
                int cur = i;

                while(nums[cur]){
                    nums[cur] = 0;
                    res++;

                    cur = nums_2[cur].idx;
                }

                res--;
            }
        }

        return res;
    }
};